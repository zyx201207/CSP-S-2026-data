#include<bits/stdc++.h>
using namespace std;
struct a{
	long long n;
	char f;
}a[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,num=0,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		 cin>>a[i].n>>a[i].f;
		 num+=a[i].n; 
	}
	int l=1,r=n;
	while(l<r)
	{
		if(a[l].f==a[r].f)
		{
			num-=min(a[l].n,a[r].n)*2;
		}
		else
		{
			num-=min(a[l].n,a[r].n)*2;
			sum+=min(a[l].n,a[r].n);
			
		}
		if(a[l].n>a[r].n)
		{
			a[l].n-=a[r].n;
			r--;
		}
		else if(a[l].n<a[r].n)
		{
			a[r].n-=a[l].n;
			l++;
		}
		else
		{
			r--;l++;
		}
	}
	cout<<sum;
	return 0;
 } 
