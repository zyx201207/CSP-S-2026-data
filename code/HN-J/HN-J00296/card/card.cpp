#include<bits/stdc++.h>
#define ci const int
#define ll long long int
using namespace std;
ci cspj=5e5+5;
ll a[cspj],b[cspj]={0},dp[cspj]={0},g[cspj]={0};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	ll n,m,dome=1,csp=0;
	cin >> n >> m;
	csp=n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	while(n--){
		ll cnt=1,phigros=1,csps=1;
		for(int i=cnt;i<=n;i++){
			if(dp[a[csps]]!=0){
				csps=dp[a[csps]];
				b[dp[a[csps]]]=a[i];
				csps++;
			}else{
				b[csps]=a[i];
				dp[a[i]]=i;
				csps++;
			}
		}
		while(b[phigros]!=0){
			g[b[phigros]]+=1; 
			b[phigros]=0;
			phigros++;
		}
		cnt++;
	}
	while(m--){
		cout << g[dome] << " ";
		dome++;
	}
} 
