#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+10;
ll n,a[N],m,ans=0,s[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	for(ll l=1,r=1;r<=n;r++){
		ll x=a[r];
		while(m-((r-l)*x-(s[r-1]-s[l-1]))<0&&l<r)l++;
		ans=max(ans,r-l+1);
	}
	cout<<ans<<"\n";
	return 0;
}
/*5 5
1 2 4 8 9*/
