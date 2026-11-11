#include<iostream>
#include<cstdio>
#include<cmath>
#include<stack>
#include<algorithm>
#include<unordered_map>
#define ll long long
using namespace std;
const int N=2e6+9;//QAQ
ll NO_USE;
ll T,n,d;
ll a[N];//Œª÷√ 
ll ans;
ll low[N],dfn[N],dp[N],cnt;
bool iis[N];
stack<ll> s;
void tarjan(ll x) {
	low[x]=dfn[x]=++cnt;
	s.push(x);
	iis[x]=1;
	for(ll i=1;i<=n;i++) {
		if(i==x) continue;
		ll dist=((i>x)?a[i]-a[x]:a[x]-a[i]);
		if(dist>d) continue;
		if(!dfn[i]) {
			tarjan(i);
			low[x]=min(low[x],low[i]);
		}
		else {
			low[x]=min(low[x],dfn[i]);
		}
	}
	if(low[x]==dfn[x]) {
		while(s.top()!=x) {
//			cout<<s.top()<<" ";
			iis[s.top()]=0;
			s.pop();
		}
//		cout<<s.top();
		iis[s.top()]=0;
		s.pop();
//		cout<<"\n";
		ans++;
	}
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>NO_USE>>T;
	while(T--) {
		cin>>n>>d;
		cnt=0;
		for(ll i=1;i<=n;i++) {
			cin>>a[i];
			dfn[i]=0;
		}
		ll s=a[2]-a[1];
		if(s>d) cout<<"0\n";
		else cout<<max(1LL,n-d-1)<<"\n";
//		else {
//			dp[1]=1;
//			for(ll i=2;i<=n;i++) {
//				for(ll j=max(1LL,i-d);j<i;j++) {
//					dp[i]+=dp[j];
//				}
//			}
//			cout<<dp[n]<<"\n";
//		}
//		ans=0;
//		tarjan(1);
//		cout<<ans<<"\n";
	}
} 

/*
“ª—€tarjan

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
