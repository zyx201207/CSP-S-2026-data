#include<bits/stdc++.h>
using namespace std;
struct yd{
	char x;
	int n;
};
yd a[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;

	for(int i=1;i<=n;i++)
	{
		cin>>a[i].n>>a[i].x;
	}
	long long cnt=0;
	int m=1;
	int l=1;
	int r=n;
	while(l<r)
	{

		if(a[l].n!=a[r].n)
		{
			if(a[l].x!=a[r].x)
			{
				cnt+=min(a[r].n,a[l].n);
			}
			if(a[l].n>a[r].n)
			{
				a[l].n-=a[r].n;
				r--;
			}
			else
			{
				a[r].n-=a[l].n;
				l++;
			}
		}
		else
		{
			if(a[l].x!=a[r].x)
			{
				cnt+=a[r].n;
			}
			l++,r--;
		}
	}
	cout<<cnt;
	return 0;
}