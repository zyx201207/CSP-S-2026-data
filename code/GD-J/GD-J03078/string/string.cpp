#include<bits/stdc++.h>
using namespace std;
long long b[200005]={0},sum=0;
char a[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,x;
	cin>>n;
	char c;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>c;
		a[i]=c;
		b[i]=x;
	}
	bool y=1;
	for(int i=1;i<n;i++)
	{
		if(a[i]!=a[i+1])
		{
			y=0;
			break;
		}
	}
	if(y) 
	{
		cout<<'0';
		return 0;
	}
	int l=1;
	int r=n;
	while(l<r)
	{
		if(b[l]>b[r])
		{
			if(a[l]!=a[r])
			{
				sum+=b[l]-b[r];
				b[l]-=b[r];
				r--;
			}
		}
		else if(b[l]<b[r])
		{
			if(a[l]!=a[r])
			{
				sum+=b[r]-b[l];
				b[r]-=b[l];
				l++;
			}
		}
		else if(b[l]==b[r])
		{
			if(a[l]!=a[r])
			{
				sum+=b[r];
				l++;
				r--;
			}
		}
		else
		{
			if(b[l]>b[r])
			{
				r--;
				b[l]-=b[r];
			}
			else
			{
				l++;
				b[r]-=b[l];
			}
		}
	}
	cout<<sum;
	return 0;
}
