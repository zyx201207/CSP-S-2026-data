#include<bits/stdc++.h>
#define int long long
using namespace std;
struct N{
	int l;
	char z;
};
N a[200020];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].l>>a[i].z;
		sum+=a[i].l;
	}
	int L=1,R=n,cnt=0;
	while(L<R)
	{
		int sum=min(a[L].l,a[R].l);
		if(a[L].z==a[R].z)
		{
			cnt+=sum;
		}
		a[L].l-=sum;
		a[R].l-=sum;
		if(a[L].l==0)
		{
			L++;
		}
		if(a[R].l==0)
		{
			R--;
		}
	}
	cout<<(sum-cnt*2-a[L].l)/2;
	return 0;
}

