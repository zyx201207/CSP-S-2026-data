#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll n,m,a[N],sum[N];
int ans;
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	for(int i=1,l=1;i<=n;i++){
		while(a[i]*(i-l+1)-sum[i]+sum[l-1]>m)l++;
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
