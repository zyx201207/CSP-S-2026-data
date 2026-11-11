#include<bits/stdc++.h>
using namespace std;
struct st
{
	char a;
	long long b;
}ar[200100];
int main()
{
	freopen("string5.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,k;
	cin>>n;
	k=n;
	long long i=1;
	while(k--)
	{
		cin>>ar[i].b>>ar[i].a;
		if(ar[i].a==ar[i-1].a)
		{
			ar[i-1].b+=ar[i].b;
			ar[i].a=' ',ar[i].b=0;
			i--;
		}
		i++;
	}
	long long l=1,r=i-1;//双指针判断是否回文
	long long ans=0;
	while(l<r)
	{
		if(ar[l].a==ar[r].a&&ar[l].b!=ar[r].b)//数量不同
		{
			if(ar[l].b>ar[r].b)
			{
				ans+=ar[l].b-ar[r].b;
				ar[r-1].b=ar[r-1].b-ar[l].b+ar[r].b;
				ar[r]=ar[l];
			}
			else if(ar[l].b>ar[r].b)
			{
				ans+=ar[r].b-ar[l].b;
				ar[r-1].b=ar[r-1].b+ar[r].b+ar[l].b;
				ar[r]=ar[l];
			}
		}
		else if(ar[l].b==ar[r].b&&ar[l].a!=ar[r].a)//字母不同 
		{
			ans+=ar[r].b;
			ar[r].a==ar[l].a; 
		}
		else//都不同 
		{
			ans+=ar[r].b;
			ar[r].a==ar[l].a; 
			if(ar[l].b>ar[r].b)
			{
				ans+=ar[l].b-ar[r].b;
				ar[r-1].b=ar[r-1].b-ar[l].b+ar[r].b;
				ar[r]=ar[l];
			}
			else if(ar[l].b>ar[r].b)
			{
				ans+=ar[r].b-ar[l].b;
				ar[r-1].b=ar[r-1].b+ar[r].b+ar[l].b;
				ar[r]=ar[l];
			}
		}
		l++;
		r--;
	} 
	cout<<ans;
	return 0;
} 
