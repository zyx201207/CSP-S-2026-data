#include<algorithm>
#include<iostream>
#define int long long
using namespace std;
const int N = 5e5;
int n,m;
int a[N+5];

int count(int l,int r,int base)
{
	int val = 0;
	for(int i=l;i<=r;i++)
		val+=base-a[i];
	
	return val;
}

bool check(int len)
{
	int cost = count(1,len,a[len]);
	if(cost<=m) return true;
	
	for(int st=2;st+len-1<=n;st++)
	{
		int en = st+len-1;
		
		cost-=a[en-1]-a[st-1];
		cost+=(a[en]-a[en-1])*(len-1);
		
		if(cost<=m) return true;
	}
	
	return false;
}

signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i]; 
	sort(a+1,a+1+n);
	
	int l = 1;
	int r = n+1;
	while(r-l>1)
	{
		int mid = (l+r)>>1;
		if(check(mid)) l = mid;
		else r = mid;
	}
	
	cout<<l;
	return 0;
}
