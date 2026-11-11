#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,sum;
int a[200005];
char c[200005];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	while(l<r)
	{
		if(c[l]==c[r])
		{
			if(a[l]>a[r])
			{
				a[l]-=a[r];
				r--;
			}
			else if(a[l]==a[r])
			{
				a[l]-=a[r];
				l++;
				r--;
			}
			else
			{
				a[r]-=a[l];
				l++;
			}
		}
		else
		{
			if(a[l]>a[r])
			{
				sum+=a[r];
				a[l]-=a[r];
				r--;
			}
			else if(a[l]==a[r])
			{
				sum+=a[l];
				a[l]-=a[r];
				l++;
				r--;
			}
			else
			{
				sum+=a[l];
				a[r]-=a[l];
				l++;
			}
		}
	}
	cout<<sum<<"\n";
	return 0;
}
/*
2026/10/31 9:02 ·Ï¸å MLE or RE

#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k,sum;
string s; 
signed main()
{
	freopen("string3.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	s=" ";
	for(int i=1;i<=n;i++)
	{
		int a;
		char c;
		cin>>a>>c;
		k+=a;
		for(int j=1;j<=a;j++)
		{
			s+=c;
		}
	}
	for(int i=1;i<=k/2;i++)
	{
		if(s[i]!=s[k-i+1])
		{
			sum++;
		}
	}
	cout<<sum<<"\n";
	return 0;
}
*/


