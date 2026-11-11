#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
long long a[500001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	ans=a[n];
	for(int i=n-1;i>n-m;i--)ans&=a[i];
	cout<<ans<<"\n";
	return 0;
}
