#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,a[N];
unsigned long long ans;
char c[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	int i=1,j=n;
	while(i<j)
	{
		if(c[i]!=c[j])
		{
			ans+=min(a[i],a[j]);
		}
		if(a[i]==a[j])
		{
			i++,j--;
		}
		else
		{
			if(a[i]>a[j])
			{
				a[i]-=a[j],j--;
			}
			else
			{
				a[j]-=a[i],i++;
			}
		}
	}
	cout<<ans;
	return 0;
}
