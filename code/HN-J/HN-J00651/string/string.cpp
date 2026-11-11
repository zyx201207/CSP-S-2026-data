#include<bits/stdc++.h>
using namespace std;
long long a[1000000005];
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,tot=0,cnt=0;
	cin>>n;
	string s,s1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++)
		{
			s[tot]+=c[i];
			tot++;
		}
	}
	int t=s.size();
	for(int i=t-1;i>=0;i--)
	{
		s1[i]=s[i];
	}
	if(s==s1)
	{
		cout<<cnt;
		return 0;
	}
	if(t%2==1)
	{
		int mid=t/2;
		for(int i=mid;i<t;i++)
		{
			s[i]=s[mid];
			cnt++;
			mid--;
		}
	}
	if(t%2==0)
	{
		int mid=t/2;
		for(int i=mid;i<t;i++)
		{
			s[i]=s[mid];
			cnt++;
			mid--;
		}
	}
	cout<<cnt;
	return 0;
}
