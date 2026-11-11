#include <bits/stdc++.h>
using namespace std;

long long n,cnt,l,r;
struct node
{
	long long x;
	char c;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].c;
	}
	l=1;
	r=n;
	while(l<r)
	{
		if(a[l].c==a[r].c)
		{
			if(a[l].x==a[r].x)
			{
				l++;
				r--;
			}
			else if(a[l].x>a[r].x)
			{
				a[l].x-=a[r].x;
				r--;
			}
			else
			{
				a[r].x-=a[l].x;
				l++;
			}
		}
		else
		{
			if(a[l].x==a[r].x)
			{
				cnt+=a[l].x;
				l++;
				r--;
			}
			else if(a[l].x>a[r].x)
			{
				cnt+=a[r].x;
				a[l].x-=a[r].x;
				r--;
			}
			else
			{
				cnt+=a[l].x;
				a[r].x-=a[l].x;
				l++;
			}
		}
	}
	cout<<cnt;
	return 0;
}
