#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e6+10;
int c,t,n,d,lst[N];
int ans,pre[N];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		ans=0;
		cin>>n>>d;
		memset(pre,0,sizeof(int)*(n+10));
		memset(lst,0,sizeof(int)*(n+10));
		for (int i=1;i<=n;i++)
		{
			cin>>lst[i];
		}
		int l=1,r=1,s=0;
		while(l<=r&&r<=n)
		{
			while(s+lst[r+1]-lst[r]<=d&&r<=n)
			{
				s+=lst[r+1]-lst[r];
				pre[r]=l;
				r++;
			}
			pre[r]=l;
			s+=lst[r+1]-lst[r];
			r++;
			while(s-(lst[l+1]-lst[l])>d&&l<r)
			{
				s-=lst[l+1]-lst[l];
				l++;
			}
			l++;
			if(l>r)l=r;
			pre[r]=l;
		}
		for (int i=1;i<=n;i++)
		{
			int p=pre[i],ne=i;
			while(p!=pre[p])
			{
				if(p+1<ne)
				{
					ans+=pre[p+2]-pre[p+1];
				}
				ne=p;
				p=pre[p];
			}
		}
		
		cout<<ans<<"\n";
	}
	return 0;
}
