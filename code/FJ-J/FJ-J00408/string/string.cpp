#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	vector<int> a(n);
	vector<char> c(n);
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>c[i];
	}
	long long ans=0;
	for(int i=0,j=n-1;;)
	{
		if(i!=j)
		{
			int tmp=min(a[i],a[j]);
			a[i]-=tmp;
			a[j]-=tmp;
			if(c[i]!=c[j])
			{
				ans+=tmp;
			}
			if(a[i]==0)
			{
				i++;
			}
			else
			{
				j--;
			}
		}
		else
		{
			break;
		}
	}
	cout<<ans<<'\n';
	return 0;
}
