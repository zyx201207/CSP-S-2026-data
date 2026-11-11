#include <bits/stdc++.h>
using namespace std;
#define ld long long
ld arr[500005];
ld f[500005];
int main(int argc, char** argv)
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ld n,m,mi;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		f[i]=1;
	}
	sort(arr,arr+n);
	for(int i=n-1;i>0;i--)
	{
		mi=m;
		for(int j=i-1;j>=0;j--)
		{
			if(arr[i]<=(arr[j]+mi))
			{
				mi=mi-arr[i]+arr[j];
				f[i]++;
			}
			else
			{
				break;
			}
		}
	}
	int ma=0;
	for(int i=0;i<n;i++)
	{
		if(ma<f[i])
		{
			ma=f[i];
		}
	}
	cout<<ma;
	return 0;
}
