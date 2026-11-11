#include<bits/stdc++.h>
using namespace std;
long long sum,n,a[200005];
char b[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false); 
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	int l=1,r=n;
	while(l<r)
	{
		if(a[l]>=a[r])
		{
			if(b[l]!=b[r])
			{
				sum+=a[r];
				a[l]-=a[r];
				r--;
			}
			else
			{
				a[l]-=a[r];
				r--;
			}
		}
		else  //a[r]>a[l]
		{
			if(b[l]!=b[r])
			{
				sum+=a[l];
				a[r]-=a[l];
				l++;
			}
			else
			{
				a[r]-=a[l];
				l++;
			}
		}
		if(a[l]==0)
		l++;
		if(a[r]==0)
		r--;
	}
	cout<<sum;
	return 0;
}

