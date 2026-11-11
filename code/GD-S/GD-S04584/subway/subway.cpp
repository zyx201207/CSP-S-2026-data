#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],k,a,t,x,y,ti,b[505][50005],tt,ans,v[500005];
bool kkk=0;

//int souzhan(int op){
//	if(v[op]==0){
//		v[op]==1;
//	}else{
//		return op+1;
//	}
//	if(kkk=1){
//		return 0;
//	}
//	for(int i=1;i<=m;i++){
//		if(b[op][y]!=0){
//			cout<<ans+b[op][y]+w[y]<<endl;
//			kkk=1;
//			return 0;
//		}
//		if(b[op][i]!=0){
//			ans+=b[op][i];
//			return i;
//		}
//	}
//}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			b[i][a]=t;//i:当前线路  a：站台  t:时间 
			if(a==m/2){
				tt+=t;
			}
		}
	}
//	if(c>=7 && c<=11){
//		for(int i=1;i<=q;i++){
//			cin>>x>>y;
//			for(int j=1;j<=m;j++){
//				v[j]=0;
//			}
//			kkk=0;
//			ans=w[x];
//			for(int j=1;j<=n;j++){
//				if(kkk){
//					break ;
//				}
//				if(b[j][x]!=0){
//					ans+=b[j][x];
//					j=souzhan(j)-1;
//				}
//			}
//		}
//		return 0;
//	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		ti+=w[x]+w[y];
		for(int j=1;j<=n;j++){
			bool hu=0;
			if(b[j][x]!=0 && b[j][y]!=0){
				ti+=b[j][x]+b[j][y];
				cout<<ti<<endl;
				break;
			}
		}
		if(ti==w[x]+w[y]){
			cout<<ti+tt<<endl;
		}
		ti=0;
	}
	return 0;
} 
