#include<iostream>
#define int long long
using namespace std;
const int N = 2e5;
int n,m;
int a[N+5];
bool can[N+5];

bool check(int x)
{
	int cnt = 0;
	for(int i=1;i<=n;i++)
	{
		if(!can[i]) continue;
		
		if(a[i]&(1<<x)) cnt++;
	}
	
	return cnt>=m;
}

void sol(int x)
{
	for(int i=1;i<=n;i++)
	{
		if(!can[i]) continue;
		
		if(! (a[i]&(1<<x)) ) can[i] = false;
	}
}

signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		can[i] = true;
	}
	
	int ans = 0;
	for(int i=30;i>=0;i--)
	{
		if(check(i))
		{
			ans|=(1<<i);
			sol(i);
		}
	}
	
	cout<<ans;
	return 0;
}
