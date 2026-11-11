#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e5+10;
ll a[maxn];
ll n,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	ll q;
	for(int i=1; i<=n; i++){
		cin>>a[i];
		q = a[i]-a[i-1];
	}
	int ans=0,ans1 = 0;
	int cnt=1;
	while(m>=q){
		for(int i=q; i<=m; i=q*cnt){
			ans1+=cnt;
			cnt++;
			m-=i;
		}
		ans1 = (ans1>n?max(n-ans1%n,ans1%n):ans1);
		ans = max(ans,ans1);
	}
	cout<<ans-1;
	return 0;
}
