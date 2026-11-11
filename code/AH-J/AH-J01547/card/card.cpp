#include<bits/stdc++.h>
using namespace std;
long long a[500005],b;
string s,ss,sss;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		s+=a[i];
	}
	for(long long i=1;i<=n;i++)
	{
		b=0;
		ss=s;
		sss="";
		for(long long j=i;j<=n;j++)
		{
			if(sss.find(ss[j])>=0)
			{
				sss.erase(sss.find(ss[j]));
			}
			sss+=ss[j];
		}
		for(long long j=0;j<sss.size();j++)
		{
			if(sss[j]==i+'0')
			{
				b++;
			}
		}
		cout<<b<<" ";
	}
}
