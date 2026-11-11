#include<bits/stdc++.h> 
using namespace std;
struct stu
{
	int x;
	string y;
}a[200005];
long long s=0;
int main()
{
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].y;
	}
	int l=1,r=n;
	while(l<r)
	{
		if(a[l].y!=a[r].y)
		{
			if(a[l].x>a[r].x)
			{
				s+=a[r].x;
				a[l].x-=a[r].x;
				r--;
			}
			else
			if(a[l].x==a[r].x)
			{
				s+=a[l].x;
				l++;
				r--;
			}
			else
			{
				s+=a[l].x;
				a[r].x-=a[l].x;
				l++;
			}
		}
		else
		{
			if(a[l].x>a[r].x)
			{
				a[l].x-=a[r].x;
				r--;
			}
			else
			if(a[l].x==a[r].x)
			{
				l++;
				r--;
			}
			else
			{
				a[r].x-=a[l].x;
				l++;
			}
		}
	}
	cout<<s;
	return 0;
}
