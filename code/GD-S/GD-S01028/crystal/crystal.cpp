#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n,o,cnt;
long long a[N],m,z;
map<long long,int> mp;
string s;
int x,y;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(mp[a[i]]==0)o++;
		mp[a[i]]++;
	}
	sort(a+1,a+n+1);
	z=a[1];
	x=1;
	y=m;
	for(int i=1,t=1;i<=o;i++,t+=mp[a[t]])
	{
		for(int r=t-1;;)
		{
			if(x>r)
			{
				z=a[t];
				break;
			}
			if((r-x+1)*(a[t]-z)<=y)
			{
				cnt=max(r-x+1+mp[a[t]],cnt);
				y=y-(r-x+1)*(a[t]-z);
				z=a[t];
				break;
			}
			else
			{
				y+=z-a[x];
				x++;
			}
		}
	}
	cout<<cnt;
	return 0;
}
