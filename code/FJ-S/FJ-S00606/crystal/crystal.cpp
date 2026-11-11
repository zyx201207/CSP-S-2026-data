#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=5e5+5;
ll n,m,a[maxn],sum[maxn],ans=1,cnt=1;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=2;i<=n;i++){
		while(a[i]*(i-cnt+1)-(sum[i]-sum[cnt-1])>m) cnt++;
		ans=max(i-cnt+1,ans);
	}
	cout<<ans;
	return 0;
} 
