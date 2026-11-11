#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

const int N=1e6+5;
int a[N];
char c[N];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	while(l<r)
	{
		if(a[l]==a[r]) 
		{
			if(c[l]!=c[r]) ans+=a[l];
			l++;
			r--;
		}
		else if(a[l]>a[r])
		{
			a[l]-=a[r];
			if(c[l]!=c[r]) ans+=a[r];
			r--;
		}
		else
		{
			a[r]-=a[l];
			if(c[l]!=c[r]) ans+=a[l];
			l++;
		}
	}
	cout<<ans;
	return 0;
}
/*
3
2 a
2 b
1 c

2
2 a
3 a

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

*/
