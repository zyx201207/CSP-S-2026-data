#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ans,s;
int a[500005];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,r=1,len=0;
	while(l<=n&&r<=n&&l<=r) //»¬¶¯´°¿Ú 
	{
		s+=a[r++];
		len++;
		while(a[r-1]*len-s>m)
		{
			len--;
			s-=a[l++];
		}
		ans=max(ans,len);
	}
	cout<<ans;
}
/*
5 5
1 2 4 8 9
*/
