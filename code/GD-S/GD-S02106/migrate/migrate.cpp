#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int n;
long long d,pos[N];
int f1[N],f2[N],f3[N];

inline long long read(long long x=0)
{
	bool f=false;
	char c;
	while((c=getchar())<'0'||c>'9')
	{
		if(c=='-')f=!f;
	}
	x=c&15;
	while((c=getchar())>='0'&&c<='9')x=x*10+(c&15);
	return f?-x:x;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int test_num;scanf("%*d %d",&test_num);while(test_num--)
	{
		scanf("%d %lld",&n,&d);
		for(int i=1;i<=n;i++)
		{
			pos[i]=read();
//			scanf("%lld",pos+i);
			f1[i]=f2[i]=f3[i]=0;
		}
		long long ans=0;
		for(int i=1,r=0,r1=0,r2=0;i<=n;i++)
		{
			r2=r1,r1=r;
			while(r<n&&pos[r+1]-pos[i]<=d)r++;
//			cout<<i<<' '<<f1[i]<<' '<<f2[i]<<' '<<f3[i]<<' '<<r<<' '<<r1<<' '<<r2<<endl;
			if(r>i+1)f2[r]++;
			else f1[r]++;
			if(r1<r)
			{
				if(r1<r-1&&r>i+1)f2[r]+=f1[i]+f2[i];
				else f1[r]+=f1[i]+f2[i];
				f3[r]+=f3[i];
				ans+=(r-max(r1,i))*(long long)f3[i];
			}
			else if(r2<r)
			{
				f3[r]+=f2[i];
			}
			if(r1>i)ans+=(r1-max(r2,i))*(long long)f2[i];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
