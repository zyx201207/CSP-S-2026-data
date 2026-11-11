#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
long long k;
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	for(int l=1,r=n;l<=r;l++)
	{
		int t1=a[l];
		while(t1>0)
		{
			if(t1>a[r])
			{
				if(c[l]!=c[r]) k+=a[r];
				t1-=a[r]; 
				r--;
			}
			else 
			{
				if(c[l]!=c[r]) k+=t1;
				a[r]-=t1;
				t1=0;
			}
		}
	}
	cout<<k;
	return 0;
}

