#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200010],L,cnt;
char c[200010];
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		L+=a[i];
		cin>>c[i];
	}
	int l=1,r=n;
	while(l<r)
	{
		if(c[l]!=c[r])
		{
			cnt+=min(a[l],a[r]);
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
	cout<<cnt;
	return 0;
}
