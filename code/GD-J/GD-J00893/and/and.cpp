#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[200005];
signed main(){
	ios::sync_with_stdio(0),cin.tie(0);
	
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int js=n;
	for(int i=29;i>=0;i--)
	{
		int now=(1<<i);
		int cc=0;
		for(int j=1;j<=js;j++)
		{
			if((a[j]&now)==now)
			{
				cc++;
			}
		}
		if(cc>=m)
		{
			cc=0;
			for(int j=1;j<=js;j++)
			{
				if((a[j]&now)==now)
				{
					cc++;
					a[cc]=a[j];
				}
			}
			js=cc;
		}
	}
	int ans=a[1];
	for(int i=1;i<=js;i++)
	{
		ans=ans&a[i];
	}
	cout<<ans;
	
	
	return 0;
}
