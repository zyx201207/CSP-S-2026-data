#include<bits/stdc++.h>
using namespace std;
string yuan,a,dait;
long long n,m,s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>m>>a;
		for(int j=1;j<=m;j++)
		{
			yuan=yuan+a;
		}
	}
	dait=yuan;
	reverse(dait.begin(),dait.end());
	if(dait==yuan)
	{
		cout<<s;
		return 0;
	}
	else
	{
		for(unsigned int i=0;i<yuan.size();i++)
		{
			if(yuan[i]!=dait[i])
			{
				s++;
			}
		}
	}
	cout<<s/2;
}
