#include<bits/stdc++.h>
using namespace std;
int n,ar[200005],m;
char ar2[200005];
long long cnt;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i = 0;i<n;i++)
	{
		cin>>ar[i]>>ar2[i];
	}
	int l = 0,r = n-1;
	while(l<=r)
	{
		if(ar2[l] == ar2[r])
		{
			if(ar[l]>ar[r])
			{
				ar[l]-=ar[r];
				r--;
			}
			else if(ar[l]<ar[r])
			{
				ar[r]-=ar[l];
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
			cnt+=min(ar[l],ar[r]);
			if(ar[l]>ar[r])
			{
				ar[l]-=ar[r];
				r--;
			}
			else if(ar[l]<ar[r])
			{
				ar[r]-=ar[l];
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
