#include<iostream>
#include<cmath>
#define ll long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
const int maxn=2000005;
ll ct,t,n,d,a[maxn];
inline bool check1()
{
	ll x=a[2]-a[1];
	for(int i=2;i<=n-1;i++)
	{
		if(a[i+1]-a[i]!=x) return false;
	}
	return true;
}
inline void tp1()
{
	ll x=a[2]-a[1];
	if(x>=d) 
	{
		cout<<0<<endl;
		return;
	} 
	ll y=d/x;
	if(y==1) 
	{
		cout<<0<<endl;
		return;
	}
	y=2*y-1;
	cout<<max(n-y,0ll)<<endl;
}
inline void fre()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
}
int main()
{
	IOS
	fre();
	cin>>ct>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		if(check1())
		{
			tp1();
			continue;
		}
	}
	return 0;
}
