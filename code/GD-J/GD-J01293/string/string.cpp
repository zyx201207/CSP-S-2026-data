#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
struct node{int x;string s;}a[N],b[N]; 
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i].x>>a[i].s,b[n-i+1]=a[i];
	int ans=0;
	int pl=0,pr=0,sum1=0,sum2=0;
	while(pl<=n&&pr<=n)
	{
		if(sum1==0)sum1=a[++pl].x;
		if(sum2==0)sum2=b[++pr].x;
		if(pl>n||pr>n)break;
		int mn=min(sum1,sum2);
		if(a[pl].s[0]!=b[pr].s[0])
		{
			ans+=mn;
		}
		sum1-=mn,sum2-=mn;
	}
	cout<<ans/2<<'\n';
	return 0;
}
