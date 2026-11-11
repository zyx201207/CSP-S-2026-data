#include<bits/stdc++.h>
#define ll long long
#define FOR(x,y,z) for(int x=y;x<=z;x++)
#define ROF(x,y,z) for(int x=y;x>=z;x--)
using namespace std;
const int N=5e5+5;
ll n,m,a[N],vis[N],ans[N],nxt[N],w[N];
stack<ll>sta;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	FOR(i,1,n)cin>>a[i];
	ROF(i,n,1){
		nxt[i]=w[a[i]];
		if(!w[a[i]])w[a[i]]=i;
	}
	FOR(i,1,n){
		memset(vis,0,sizeof(vis));
		FOR(j,i,n){
			if(!vis[a[j]]){
				sta.push(a[j]);
				vis[a[j]]=1;
				if(nxt[j])j=nxt[j];
			}else{
				while(sta.top()!=a[j]){
					vis[sta.top()]=0;
					sta.pop();
				}
			}
		}
		while(!sta.empty()){
			ans[sta.top()]++;
			sta.pop();
		}
	}
	FOR(i,1,m){
		cout<<ans[i];
		if(i!=m)cout<<" ";
	}
	return 0;
}

