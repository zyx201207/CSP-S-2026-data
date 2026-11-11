#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m;
int a[N];
int s[N];
int maxs=INT_MIN;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int f=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i]=s[i-1]+(a[i]-a[i-1])*(i-1);
		if(s[i]>m)
		{
			cout<<i-1;
			f=1;
			break;
		}
	}
	if(!f)
	{
		cout<<0;
	}	
		 
	return 0;
}
               