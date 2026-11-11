#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
ll a[N];
bool f[N];
int n,m;
bool check(int x)
{
	int cnt=0;
	for(int i=1;i<=n;i++)
		if(((a[i]>>x)&1)!=0&&f[i]) cnt++;
	return cnt>=m;
}
void change(int x)
{
	for(int i=1;i<=n;i++)
		if(((a[i]>>x)&1)==0) f[i]=0;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("add.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	memset(f,1,sizeof(f));
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	ll ans=0;
	for(int i=30;i>=0;i--)
	{
		if(check(i))
		{
			change(i);
			ans+=(1LL<<i);
		}
	}
	cout<<ans;
	return 0;
}
