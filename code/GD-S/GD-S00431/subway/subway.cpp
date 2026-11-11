#include<bits/stdc++.h>
using namespace std;
int w[500001],k[500001];
//struct node{
//	int a,t,d[501],num;
//}z[505][50001];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
//	for(int i=1;i<=n;i++){
//		cin>>k[i];
//		for(int j=1;j<=k[i];j++){
//			cin>>z[i][j].a>>z[i][j].t;
//		}
//	}
//	while(q--){
//		int x,y,ans=0;
//		cin>>x>>y;
//		ans+=w[x];
//		bool f=0;
//		for(int i=1;i<=n;i++){
//			for(int b=i+1;b<=n;b++){
//				for(int j=1;j<=k[i];j++){
//				  	if(z[i][j].a==z[b][j].a){
//				  		z[i][j].num++;
//				  		z[b][j].num++;
//				  		z[i][j].d[z[i][j].num]=k[b];
//				  		z[b][j].d[z[b][j].num]=k[i];
//				  		int c=z[i][j].num,c1=z[b][j].num,d1=z[i][j].d[z[i][j].num],d2=z[b][j].d[z[b][j].num];
//				  		cout<<c<<" "<<d1<<endl;
//				  		cout<<c1<<" "<<d2<<endl;
//					}
//				}
//			}
//		}
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=k[i];j++){
//				if(z[i][j].a==y){
//					ans+=z[i][j].t;
//					break;
//					f=1;
//				}
//			}
//			if(f){
//				break;
//			}
//		}
//		if(f){
//			continue;
//		}
//		cout<<ans<<endl;
//	}
	return 0;
}

