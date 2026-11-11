#include<bits/stdc++.h>
using namespace std;
int c,t;
int n;
long long d;
long long x[2000010];
long long ans;
struct node
{
	int a,b;
};
node w[2000010];
void init()
{
	memset(w,0,sizeof(w));
	memset(x,0,sizeof(x));
	ans=0;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	int l,r,mid,a,b,oa,ob;
	while(t--)
	{
		init();
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&x[i]);
		}
		for(int i=1;i<=n;i++)
		{
			//最左端可以到的地方
			l=1;r=i;
			while(l<=r)
			{
				mid=(l+r)>>1;
				if(x[i]-x[mid]>d)
				{
					l=mid+1;
				}
				else
				{
					r=mid-1;
				}
			}
			r++;
			w[i].a=r;
			//最右端可以到的地方
			l=i;r=n;
			while(l<=r)
			{
				mid=(l+r)>>1;
				if(x[mid]-x[i]>d)
				{
					r=mid-1;
				}
				else
				{
					l=mid+1;
				}
			}
			l--;
			w[i].b=l;
		}
//		for(int i=1;i<=n;i++)
//		{
//			cout<<w[i].a<<" "<<w[i].b<<"____"<<endl;
//		}
		for(int i=1;i<n;i++)
		{
			a=w[i].a;
			b=w[i].b;
			b--;
			if(b<a)
			{
				continue;
			}
			l=b+2;r=n;
			while(l<=r)
			{
				mid=(l+r)>>1;
				if(w[mid].a>=b)
				{
					r=mid-1;
				}
				else
				{
					l=mid+1;
				}
			}
			r++;
//			cout<<i<<": "<<r<<" "<<w[r].a<<endl;
			if(w[r].a==b)
			{
				oa=r;
			}
			else
			{
				continue;
			}
			l=b+2;r=n;
			while(l<=r)
			{
				mid=(l+r)>>1;
				if(w[mid].a>b)
				{
					r=mid-1;
				}
				else
				{
					l=mid+1;
				}
			}
			l--;
			ob=l;
//			cout<<i<<": "<<oa<<" "<<ob<<endl;
			ans+=(long long)ob-oa+1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}

