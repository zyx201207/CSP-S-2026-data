#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,ans;
struct bsc
{
	int m;
	char c;
}a[200005];
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d %c",&a[i].m,&a[i].c);
	}
	int l=1,r=n;
	while(l<r)
	{
		if(a[l].c!=a[r].c) ans+=min(a[l].m,a[r].m);
		if(a[l].m<a[r].m) a[r].m-=a[l].m,l++;
		else if(a[l].m>a[r].m) a[l].m-=a[r].m,r--;
		else l++,r--;
	}
	cout<<ans;
	return 0;
}
