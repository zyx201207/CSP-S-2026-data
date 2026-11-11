#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int maxn=2e5+5,mod=1e9+7;
ll v[maxn];
struct node{
	ll to,w;
};
struct e{
	ll d,w;
	bool operator<(const e &a)const{return w>a.w;}
};
vector<node> a[maxn];
ll dis[maxn];
ll dp[maxn];
ll dij(ll s,ll n){
	priority_queue<e> q;
	q.push({s,0});
	for (int i=1;i<=n;i++) dp[i]=0,dis[i]=2e18;
	dis[s]=0;
	ll cnt=0;
	while (!q.empty()){
		e r=q.top();
		q.pop();
		for (int i=0;i<a[r.d].size();i++){
			node j=a[r.d][i];
			if (dis[j.to]==r.w+j.w && dis[j.to]!=2e18) dp[j.to]++;	
			if (dis[j.to]>r.w+j.w){
				dis[j.to]=r.w+j.w;
				dp[j.to]=1;
			}
			q.push({j.to,r.w+j.w});
		} 
	}
	for (int i=1;i<=n;i++){
		if (dp[i]==2)cnt++; 
		
	} 
	return cnt;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while (t--){
		ll n,d;
		cin>>n>>d;
		for (int i=1;i<=n;i++) cin>>v[i],a[i].clear();
		for (int i=1;i<=n;i++){
			for (int j=i+1;j<=n;j++){
				if (v[j]-v[i]<=d) a[i].push_back({j,1});
			}
		}
		ll ans=0;
		for (int i=1;i<=n;i++) ans+=dij(i,n);
		cout<<ans<<endl;
	}


	fclose(stdin);
	fclose(stdout);
	return 0;
}



