#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2*1e5+10;
int a[N];
int a2[N];
char c2[N];
char c[N];
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int L = 0;
	string s = "";
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cin>>c[i];
		L+=a[i];
	}
	int index = 1;
	a2[1]=a[1];
	c2[1]=c[1];
	for(int i=2;i<=n;i++)
	{
		if(c[i]==c[i-1])
		{
			a2[index]+=a[i];
		}
		else
		{
			index++;
			a2[index] = a[i];
			c2[index] = c[i];
			
		}
	}
	// for(int i=1;i<=index;i++)
	// {
	// 	cout<<a2[i]<<c2[i];
	// }
	int n2=index;
	int l = 1;
	int r = n2;
	int ans = 0;
	while(l<r)
	{
		int xiao=min(a2[l],a2[r]);
		// cout<<xiao<<' '<<a2[l]<<' '<<a2[r]<<' '<<endl;
		if(c2[l]!=c2[r])
			ans+=xiao;
		a2[l]-=xiao;
		a2[r]-=xiao;
		// cout<<xiao<<' '<<a2[l]<<' '<<a2[r]<<' '<<l<<' '<<r<<endl;
		if(a2[l]==0)
			l++;
		if(a2[r]==0)
			r--;
		// cout<<xiao<<' '<<a2[l]<<' '<<a2[r]<<' '<<l<<' '<<r<<endl;
	}
	
	cout<<ans;
	return 0;
}
