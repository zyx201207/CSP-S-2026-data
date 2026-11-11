#include<bits/stdc++.h>
using namespace std;
string s;
long long n,ans,b;
int a[200005];
char c[200005];
int main()
{
	cin.tie(0);cout.tie(0);
	freopen("string.in","w",stdin);
	freopen("string.out","r",stdout);
	cin>>n; 
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	for(int i=1,j=n;i<=j;)
	{
		if(a[i]>=a[j])
		{
			if(c[i]!=c[j])
			{
				ans+=a[j];
			}
			a[i]-=a[j];
			j--;
			b=0;
		}
		else
		{
			if(c[i]!=c[j])
			{
				ans+=a[i];
			}
			a[j]-=a[i];
			i++;
			b=1;
		}
	}
	cout<<ans;
	return 0;
}

