#include<bits/stdc++.h>
using namespace std;
long long a[200001];
char b[200001]; 
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	long long cnt=0;
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		cnt+=a[i];
	}
	long long mid,tot=0,ans=0,l=0,r=0;
	if(cnt%2)
	{
		mid=cnt/2+1;
		for(long long i=1;i<=n;i++)
		{
			tot+=a[i];
			if(tot>=mid)
			{
				a[i]--;
				l=i;
				r=i+1;
				if(r>n)
				{
					r--;
					l--;
				}
				break;
			}
		}
	}
	else{
		mid=cnt/2;
		for(long long i=1;i<=n;i++)
		{
			tot+=a[i];
			if(tot>=mid)
			{
				if(mid+1<=tot) a[i]-=2;
				if(mid+1>tot)
				{
					if(b[i]!=b[i+1])
					{
						ans++;
						a[i]--;
						a[i+1]--;
					}
				}
				l=i;
				r=i+1;
				if(r>n)
				{
					r--;
					l--;
				}
				break;
			}
		}
	}
	while(l>0||r<=n)
	{
		if(r>=n&&l<=1 || l<=0 &&r>=n-1)break;
		if(b[l]!=b[r])
		{
			if(a[l]>a[r])
			{
				ans+=a[r];
				r++;
				a[l]-=a[r];
			}
			else if(a[l]<a[r])
			{
				ans+=a[l];
				l--;
				a[r]-=a[l];
			}
			else
			{
				ans+=a[l];
				l--;
				r++;
			}
		}
		else
		{
			if(a[l]>a[r])
			{
				r++;
				a[l]-=a[r];
			}
			else if(a[l]<a[r])
			{
				l--;
				a[r]-=a[l];
			}
			else
			{
				l--;
				r++;
			}
		}
	}
	cout<<ans;
	return 0;
}
