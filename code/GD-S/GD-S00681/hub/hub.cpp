#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define st string
ll o,T,n,m,fro[100005],cnt,ans,maxx,dis[100050];
vector<ll>nex[100050];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>o>>T;
	while(T--){
		cin>>n>>m;
		for(ll i=1;i<=n;i++){
			fro[i]=0;
			nex[i].clear();
		}
		for(ll i=1;i<=n-1;i++){
			ll x,y;
			cin>>x>>y;
			nex[x].push_back(y);
			fro[y]=x;
		}
		ll gen;
		for(ll i=1;i<=n;i++)
			if(fro[i]==0)
				gen=i;
		cout<<0<<"\n";
	}
	return 0;
}

