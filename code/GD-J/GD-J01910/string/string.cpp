#include <bits/stdc++.h>
using namespace std;
int n;
long long a[200005],ans;
char x[200005];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>x[i];
	}
	int i=1,j=n;
	while(i<j)
	{
		if(a[i]==a[j])
		{
			if(x[i]!=x[j])
			{
				ans+=a[i];
			}
			i++;
			j--;
		}
		else if(a[i]>a[j])
		{
			if(x[i]!=x[j])
			{
				ans+=a[j];
			}
			a[i]-=a[j];
			j--;
		}
		else
		{
			if(x[i]!=x[j])
			{
				ans+=a[i];
			}
			a[j]-=a[i];
			i++;
		}
	}
	cout<<ans;
	
	return 0;
}
