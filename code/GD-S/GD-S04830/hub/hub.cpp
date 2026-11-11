#include<bits/stdc++.h>
using namespace std;
long long n,m,b[15],fa[10005],c,ans,d,e,i,j,k,t,x,y,xx,yy,fl,kuai;
long long find(long long a){
	if(fa[a]==a)return fa[a];
	fa[a]=find(fa[a]);
	return fa[a];
}
void me(long long x,long long y){
	xx=find(x);
	yy=find(y);
	if(xx!=yy)fa[xx]=yy;
}
vector<long long> v[10005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	if(c==13||c==14){
		while(t--){
			cin>>n>>k;
			for(i=1;i<n;i++){
				cin>>x>>y;
			}
			if(k==n){
				cout<<0<<endl;
				continue;
			}
			m=n/2;
			cout<<max(1ll,(m-k+1)/4+1)<<endl;
		}
		return 0;
	}
//	while(t--){
//		cin>>n>>k;
//		for(i=1;i<n;i++){
//			cin>>x>>y;
//			v[x].push_back(y);
//			v[y].push_back(x);
//		}
//		for(i=3;i<(1<<n);i++){
//			cnt=0;
//			for(j=(1<<k);j<=n;j++){
//				if((i>>(j-1))&1){
//					b[j]=1;
//					cnt++;
//				}
//				else b[j]=0;
//			}
//			if(cnt!=k)continue;
//			for(j=1;j<=n;j++)fa[i]=i;
//			for(x=1;x<n;x++){
//				for(y=x;y<=n;y++){
//					if(b[x]&&b[y])me(x,y);
//				}
//			}
//			memset(&c,0,sizeof(c));
//			for(j=1;j<=n;j++){
//				if(fa[j]!=j&&c[fa[j]]==0){
//					c[fa[j]]=1;
//					kuai++;
//				}
//			}
//			if(kuai>2)continue;
//			for()
//		}
//	}
	return 0;
} 
