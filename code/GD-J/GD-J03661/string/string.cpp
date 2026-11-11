#include <bits/stdc++.h>
using namespace std;
int n; 
int a[200005];
char s[200005];
long long cnt=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cin>>s[i];
	}
	int l=1,r=n;
	while(l<r)
	{
		if(s[l]!=s[r])cnt=cnt+min(a[l],a[r]);
		if(a[l]>a[r])
		{
			a[l]=a[l]-a[r];
			r--;
		}
		else if(a[r]>a[l])
		{
			a[r]=a[r]-a[l];
			l++;
		}
		else 
		{
			l++;
			r--;
		}
	}
	cout<<cnt;
	return 0;
}
 
