//按二进制中1的数量排序+特判。选择排序50分，正解可能是二分或O(nlogn)排序
#include<bits/stdc++.h> 
using namespace std;
#define ll long long
const int N=200005;
const ll M=549755813887; 
bool cmp(ll c,ll b)
{
	ll m1=0,m2=0,x=c,y=b;
	while(c)
	{
		m1+=c%2;
		c/=2;
	}
	while(b)
	{
		m2+=b%2;
		b/=2;
	}
	if(m1==m2)
	{
		return x<y;
	}
	else
	{
		return m1<m2;
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll n,m,a[N];
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	ll ans=a[n];
//	for(int i=1;i<=n;i++)
//	{
//		cout<<a[i]<<" ";
//	}
////	cout<<endl;
//	cout<<endl;
//cout<<a[n]<<" ";	
ll x=n-m+1;
	for(ll i=n-1;i>=x;i--)
	{
//		if(a[i]>ans)
//		{
//			x--;
//			continue;
//		 } 
//		cout<<a[i]<<" ";
		ans&=a[i];
	}
	cout<<ans;
	return 0;
} 
