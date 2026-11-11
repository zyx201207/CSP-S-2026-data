#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
#define int long long
struct node
{
	int l,r;
	char c;
}a[N];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,lst=1,sum=0,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int len;
		cin>>len>>a[i].c;
		a[i].l=lst,a[i].r=lst+len-1;
		sum+=len,lst=a[i].r+1;
	}
	for(int i=1,j=n;i<=n;i++)
	{
		if(i>=j) break;
		while(a[i].r-a[i].l+1>a[j].r-a[j].l+1)
		{
			if(a[i].c!=a[j].c) ans+=a[j].r-a[j].l+1;
			a[i].l=a[i].l+a[j].r-a[j].l+1,j--;
		}
		if(a[i].r-a[i].l+1==a[j].r-a[j].l+1)
		{
			if(a[i].c!=a[j].c) ans+=a[j].r-a[j].l+1;
			j--;
			continue;
		}
		if(a[i].c!=a[j].c) ans+=a[i].r-a[i].l+1;
		a[j].r=sum-a[i].r;
	}
	cout<<ans;
	return 0;
}
