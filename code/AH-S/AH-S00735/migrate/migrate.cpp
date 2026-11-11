#include<bits/stdc++.h>
using namespace std;
long long c,t,n,m,a[5002],z=0,bs=0,zgb[5002],mxa=-1,mia=INT_MAX,mib=INT_MAX,s=0,minq[5002];
struct e{
	long long zhi,bu;
};
queue<e> b;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	memset(a,0,sizeof(a));
	memset(zgb,0,sizeof(zgb));
	memset(minq,INT_MAX,sizeof(minq));
	for(int i=0;i<t;i++)
	{
		cin>>n>>m;
		for(int j=0;j<n;j++)
		{
			cin>>a[j];
			if(a[j]>=mxa)
			{
				mxa=a[j];
			}
			if(a[j]<=mia)
			{
				mia=a[j]+m;
			}
		}
		for(int j=0;j<n;j++)
		{
			b.push({a[j],0});
			while(!b.empty())
			{
				z=b.front().zhi;
				bs=b.front().bu;
				b.pop();
				for(int k=m;k>=1;k--)
				{
					if(z+k<a[n-1])
					{
						b.push({ a[z+k] ,bs+1});
						if(minq[a[z+k]]>bs+1)
						{
							minq[a[z+k]]=bs+1;
						}
					}
				}
			}
		}
		for(int j=0;j<n;j++)
		{
			b.push({a[j],0});
			while(!b.empty())
			{
				z=b.front().zhi;
				bs=b.front().bu;
				b.pop();
				for(int k=m;k>=1;k--)
				{
					if(z+k<a[n-1])
					{
						b.push({ a[z+k] ,bs+1});
						if(minq[a[z+k]]==bs+1)
						{
							zgb[a[z+k]]+=1;
						}
					}
				}
			}
		}
		for(int j=mia;j<=mxa;j++)
		{
			if(zgb[j]==2)
			{
				s+=1;
			}
		}
		cout<<s<<endl;
	}
	return 0;
}
