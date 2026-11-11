#include<bits/stdc++.h>
using namespace std;
int c,t,fa[100005],sum;
int f(int x){
	if(fa[x]!=x)return fa[x]=f(fa[x]);
	return x;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			fa[i]=i;
		}
		for(int i=1;i<=n-1;i++){
			int u,v;
			cin>>u>>v;
			int x=f(u);
			int y=f(v);
			if(x!=y){
				sum++;
				fa[x]=y;
			}
		}
		cout<<sum/2<<endl;;
		
	}
	return 0;
} 
