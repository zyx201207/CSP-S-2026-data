#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;

int n, m;
int a[N], sum[N];

bool check(int x)
{
	for(int i=x; i<=n; i++)
	{
		if(a[i]*x-(sum[i]-sum[i-x])<=m) return true;
	}
	return false;
}

signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin>>n>>m;
	for(int i=1; i<=n; i++) cin>>a[i];
	sort(a+1, a+n+1);
	for(int i=1; i<=n; i++) sum[i]=sum[i-1]+a[i];
	
	
	
	int L=1, R=n;
	while(L<R)
	{
		int mid=(L+R+1)>>1;
		if(check(mid)) L=mid;
		else R=mid-1;
	}
	cout<<L<<endl;
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
