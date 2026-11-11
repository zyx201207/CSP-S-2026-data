#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pb push_back
const int N=5e5+10;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll MOD=998244353;
ll n,m,a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	ll sum=0,ans=0;
	for(int i=1,j=1;i<=n;i++){
		if(i>1)sum+=((i-j)*(a[i]-a[i-1]));
		while(sum>m)sum-=(a[i]-a[j]),j++;
		ans=max(ans,i-j+1ll);
	}
	cout<<ans;
	return 0;
} 
