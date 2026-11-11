#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500010];
bool check(int x){
	int minl=2e18,s=0;
	for(int i=1;i<=x;i++)s+=a[i];
	minl=min(minl,a[x]*x-s);
	for(int i=x+1;i<=n;i++){
		s-=a[i-x];s+=a[i];
		minl=min(minl,a[i]*x-s);
	}
	return (minl<=m);
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int L=1,R=n,mid;
	while(L<R){
		int mid=(L+R+1)/2;
		if(check(mid))L=mid;
		else R=mid-1;
	}
	cout<<L;
}
