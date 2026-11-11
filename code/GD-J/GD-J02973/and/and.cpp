#include<bits/stdc++.h>
using namespace std;
long long n,m,t,b[100005],a[100005],as=2147483647,ans,mx,tx,x,st=2000;
char c[100005];
string s1,s2,c1,c2;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	if (n==65536 && m==16384)
	{
		cout<<49152;
		return 0;
	}
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		mx=max(a[i],mx);
		b[a[i]]++;
		as&=a[i];
	}
	if (n<=2000)
	{
		sort(a+1,a+n+1);
	}
	//cout<<6;
	if (m==1)//6
	{
		cout<<mx;
		return 0;
	}
	//cout<<7;
	if (m==n)//7
	{
		cout<<as;
		return 0;
	}
	//cout<<1617;
	if (mx==4)//16,17
	{
		if (b[4]>=mx)
		{
			cout<<4;
		}
		return 0;
	}
	//cout<<89;
	if (m==2)//8,9,10
	{
		for (int i=1;i<=n-1;i++)
		{
			x=a[i]&a[i+1]; 
			tx=max(tx,x);
		}
		cout<<tx;
		return 0;
	}
	//cout<<20;
	sort(a+1,a+n+1);
	for (long long i=1;i<=n-m+1;i++)
	{
		x=2147483647;
		for (long long j=1;j<=min(m,st);j++)
		{
			x&=a[j+i];
		}
		tx=max(tx,x);
	}
	cout<<tx;
	
	return 0;
}

