#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,n,m,d,q;
int w[500005];
struct node{
	int a,t;
};
vector<node> po[500005];
int k[505];

struct Node{
	map<int,ll> mp;
}sub[505];
ll floy[505][505];
vector<int> cao;
int flag[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			ll cur1,cur2;
			cin>>cur1>>cur2;
			node curr;
			curr.a=i,curr.t=cur2;
			po[cur1].push_back(curr);
			sub[i].mp[cur1]=cur2;
			if(!flag[cur1])
			{
				cao.push_back(cur1);
				flag[cur1]=1;
			}
		}
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++)
		floy[i][j]=1e18+7;
		floy[i][i]=0;
	}
	for(int xx=0,i;xx<=cao.size();xx++){
		i=cao[xx];
		if(po[i].size()>1){
			for(ll j=0;j<po[i].size();j++){
				for(ll q=0;q<po[i].size();q++){
					if(po[i][j].a==po[i][q].a)
					continue;
					floy[po[i][j].a][po[i][q].a]=po[i][j].t+po[i][q].t;
				}
			}
		}
	}
	for(ll k=1;k<=n;k++){
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=n;j++){
				if(floy[i][k]!=1e18+7&&floy[k][j]!=1e18+7)
				floy[i][j]=min(floy[i][j],floy[i][k]+floy[k][j]);
			}
		}
	}
	for(ll i=1;i<=q;i++){
		ll x,y;
		cin>>x>>y;
		ll ans=1e18+7;
		for(ll j=0;j<po[x].size();j++){
				for(ll q=0;q<po[y].size();q++){
				{
					if(floy[po[x][j].a][po[y][q].a]!=1e18+7)
					ans=min(ans,sub[po[y][q].a].mp[y]+sub[po[x][j].a].mp[x]+floy[po[x][j].a][po[y][q].a]);
				}
			}
		}
		ans+=w[x]+w[y];
		cout<<ans<<"\n";
	}
	return 0;
}
