#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,l,sum,ans;
int a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	l=1;
	for(int i=1;i<=n;i++){
		sum+=(a[i]-a[i-1])*(i-l);
		while(sum>m)sum-=a[i]-a[l++];
		ans=max(ans,i-l+1);
	}cout<<ans;
	return 0;
}

