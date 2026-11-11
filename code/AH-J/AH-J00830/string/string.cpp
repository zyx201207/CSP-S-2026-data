#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],ans;
char s[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>s[i];
	long long l=a[1],r=a[n];
	for(int i=1,j=n;i<j;)
	{
		if(s[i]!=s[j])
		{
			if(l>r)
			{
				ans+=r;
				l-=r;
				j--;
				r=a[j];
			}
			else
			{
				ans+=l;
				r-=l;
				i++;
				l=a[i];
			}
		}
		else
		{
			if(l>r)
			{
				l-=r;
				j--;
				r=a[j];
			}
			else
			{
				r-=l;
				i++;
				l=a[i];
			}
		}
	}
	cout<<ans;
	return 0;
}
