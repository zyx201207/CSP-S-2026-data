#include <bits/stdc++.h>
using namespace std;
int n,a[200001],j=1;
long long num,ans;
string s="";
char c[200001];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		num+=a[i];
	}
	if(num%2==1)num--;
	for(long long i=0;i<(num/2);i+=a[j],j++)
	{
		int p=a[j],q=a[n];
		while(1)
		{
			if(c[j]!=c[n])
			{
				if(p<=q)
				{
					ans+=p;
					q-=p;
					if(q==0)n--;
					break;
				}
				else
				{
					ans+=q;
					p-=q;
					n--;
					q=a[n];
				}
			}
			else
			{
				if(p<=q)
				{
					if(p==q)
					  n--;
					break;
				}
				if(p>q)
				{
					n--;
					p-=q;
					q=a[n];
				}
			}
		}
	}
	cout<<ans;
}
