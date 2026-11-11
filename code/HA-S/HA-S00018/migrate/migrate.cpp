#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define MAXN 2000005

ll c,d,x[MAXN],t,cnt,vis[MAXN],n,minn;

vector<ll>ans;

map<ll,ll>mp;

void dfs(ll sta,ll e,ll now){
	if(now==e){
		if(ans.size()<minn){
			minn=ans.size();
		}
		mp[ans.size()]++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(i!=now&&i!=sta&&vis[i]==0&&abs(x[i]-x[now])<=d){
			vis[i]=1;
			ans.push_back(i);
			dfs(sta,e,i);
			ans.pop_back();
			vis[i]=0;
		}
	}
	return;
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		memset(x,0,sizeof x);
		memset(vis,0,sizeof vis);
		cnt=0;
		cin>>n>>d;
		minn=LLONG_MAX;
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				minn=LLONG_MAX;
				mp.clear();
				dfs(i,j,i);
				ll sum=0;
				if(mp[minn]==2) cnt++;
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
}
