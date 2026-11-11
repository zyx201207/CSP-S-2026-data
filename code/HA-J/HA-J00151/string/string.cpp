#include<bits/stdc++.h>
using namespace std;
int n;
const int N=2e6+10;
long long a[N];
char p[N];
long long s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w".stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];cin>>p[i];
	}

	for(int l=1,r=n;l<r;)
	{
		if(p[l]!=p[r])
		{
			if(a[l]>a[r])
			{
				s+=a[r];
				a[l]-=a[r];
				r--;
			
			}
			else if(a[l]<a[r])
			{
				s+=a[l];
				a[r]-=a[l];
				l++;
			
			}
			else
			{
				s+=a[l];
				l++;
				r--;
			
			}
		}
		else
		{
			if(a[l]>a[r])
			{
				a[l]-=a[r];
				r--;
			
			}
			else if(a[l]<a[r])
			{
				a[r]-=a[l];
				l++;
			
			}
			else
			{
				l++;
				r--;
				
			}
		}
	}
	
	cout<<s;
	return 0;
}

