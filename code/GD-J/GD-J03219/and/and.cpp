#include <bits/stdc++.h>
using namespace std;
struct number
{
	long long x;
	int cnt;
};
vector<number> a;
void check(long long t)
{
	long long s=t;
	int ans=0;
	while(t!=1)
	{
		if(t%2==1)
		{
			ans++;
			t=(t-1)/2;
		}
		else
		{
			t=t/2;
		}
	}
	a.push_back({s,ans});
}
bool cmp(number b,number c)
{
	if(b.cnt==c.cnt)
	{
		return b.x>c.x;
	}
	return b.cnt>c.cnt;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		long long t;
		cin>>t;
		check(t);
	}
	sort(a.begin(),a.end(),cmp);
	long long num=a[0].x;
	for(int i=1;i<m;i++)
	{
		num&=a[i].x;
	}
	cout<<num;
	return 0;
}
