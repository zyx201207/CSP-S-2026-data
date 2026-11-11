#include<bits/stdc++.h>
using namespace std;
long long n,ans;

struct node
{
	int shu;
	char zi;
}a[10000009];

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int as;
		char b;
		cin>>as>>b;
		a[i].shu=as;
		a[i].zi=b;
	}
	int r=1,l=n;
	while(l>r)
	{
		int x=a[r].shu,xx=a[l].shu;
		char y=a[r].zi,yy=a[l].zi;
		if(y==yy)
		{
			if(x>xx)
			{
				a[r].shu-=a[l].shu;
				l--;
			}
			else if(xx>x)
			{
				a[l].shu-=a[r].shu;
				r++;
			}
			else
			{
				l--;
				r++;
			}
		}
		else
		{
			if(x>xx)
			{
				a[r].shu-=a[l].shu;
				ans+=a[l].shu;
				l--;
			}
			else if(xx>x)
			{
				a[l].shu-=a[r].shu;
				ans+=a[r].shu;
				r++;
			}
			else
			{
				ans+=a[l].shu;
				l--;
				r++;
			}
		}
	}
	cout<<ans;
	return 0;
}
