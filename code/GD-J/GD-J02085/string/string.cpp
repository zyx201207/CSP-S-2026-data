#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,len,ans;
struct Str{int l,r,x;char c;};
Str a[200005];
int opp(int x){return len-x+1;}
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x1;
		char ch;
		cin>>x1>>ch;
		a[i]={a[i-1].r+1,a[i-1].r+x1,x1,ch};
		len+=x1;
	}
	int i=1,j=n;
	while(i<j)
	{
		if(a[i].x==a[j].x)
		{
			if(a[i].c!=a[j].c)
			ans+=a[i].x;
			i++,j--;
			continue;
		}
		if(a[i].x>a[j].x)
		{
			if(a[i].c!=a[j].c)
			ans+=a[j].x;
			a[i].l=opp(a[j].l)+1;
			a[i].x-=a[j].x;
			j--;
			continue;
		}
		if(a[i].x<a[j].x)
		{
			if(a[i].c!=a[j].c)
			ans+=a[i].x;
			a[j].r=opp(a[i].r)-1;
			a[j].x-=a[i].x;
			i++;
		}
	}
	cout<<ans;
	return 0;
}

