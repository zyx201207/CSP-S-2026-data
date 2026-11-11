#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e6+5;
int c,t,n;
ll m,ans;
ll x[N];
map<pair<int,int>,pair<int,ll>> dis;
void dij(int s){
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
	q.push({0,s});
	while(q.size()){
		auto f = q.top();
		int now = f.first , u = f.second;
		q.pop();
		if(dis[{s,u}].first > now)dis[{s,u}].first = now;
		if(dis[{s,u}].first < now)continue;
		dis[{s,u}].second++;
		int idx = upper_bound(x+u+1,x+n+1,x[u]+m)-x-1;
		for(int i=u+1;i<=idx;i++)q.push({now+1,i});
		//if(x[u+1]-x[u]>m&&u<n)q.push({now+1,u+1});
	}for(int i=s;i<=n;i++)if(dis[{s,i}].second==2)ans++;
	return;
}void solve(){
	dis.clear();
	ans = 0;
	scanf("%d",&n);
	scanf("%lld",&m);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dis[{i,j}].first = 1e9+5;
	for(int i=1;i<=n;i++)scanf("%lld",&x[i]);
	for(int i=1;i<=n;i++)dij(i);
	printf("%lld\n",ans);
	/*
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++)cout << "  ";
		for(int j=i+1;j<=n;j++)cout << dis[{i,j}].second << " ";
		cout << endl;
	}*/
	return;
}int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--)solve();
	return 0;	
} 
