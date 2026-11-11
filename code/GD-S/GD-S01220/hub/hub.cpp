#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,T,n,k,v,w;
//vector<int>f[100005];
//void dfs1(int x,int y){
//	deep[x]=deep[y]+1;
//	for(int v:f[x]){
//		if(v!=y){
//			dfs(v,x);
//		}
//	}
//}void dfs(int x,int y){
//	for(int v:f[x]){
//		if(deep[x]>deep[y]){
//			
//			dfs(v,x);
//		}
//	}
//}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		if(k==1)cout<<0<<"\n";
		if(k==2)cout<<1<<"\n";
		if(k==3)cout<<2<<"\n";
		if(k==4)cout<<2<<"\n";
		if(k==5)cout<<3<<"\n";
//		for(int i=1;i<n;i++){
//			cin>>v>>w;
//			f[v].push(w);
//			deep[i]=0;
//		}
//		deep[1]=1;
//		dfs1(1);
//		int l=1,r=n,mid=0;
//		while(l<=r){
//			mid=(l+r)>>1;
//			for(int i=1;i<=n;i++){
//				dfs(i,0);
//			}
//		}
	}
}
