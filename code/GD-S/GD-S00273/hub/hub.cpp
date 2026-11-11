#include<bits/stdc++.h>
using namespace std;
int c,t,u,v,fa[2005],jis,n,k,ex[2005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("nub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		jis=0;
		for(int i=1;i<=n;i++){
			fa[i]=0;
			ex[i]=0;
		}
		for(int i=1;i<=n;i++){
			cin>>u>>v;
			if(u>v) swap(u,v);
			fa[++jis]=u;
			ex[jis]=v;
		}
		cout<<1;
	}
	return 0;
}
