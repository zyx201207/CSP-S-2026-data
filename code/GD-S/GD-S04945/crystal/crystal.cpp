#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+10;
long long n,m,ans,maxx=-1e9;
struct Ende
{
	long long a,b;
}e[N];
bool cmp(Ende x,Ende y)
{
	return x.a<y.a;
}
bool cup(Ende x,Ende y)
{
	return x.b<y.b;
}
void f(long long x)
{
	if(x>=m)
	{
		for(int i=1;i<=n;i++)
		{
			ans=0;
			for(int j=i;j<=n;j++)
			{
				if(e[i].a==e[j].a)
					ans++;
				//cout<<i<<":"<<e[i].a<<" "<<e[j].a<<" ";
			}
			maxx=max(ans,maxx);
//			cout<<endl<<i<<":"<<maxx<<endl;
		}
		return;
	}
	for(int i=1;i<=n;i++)
	{
		e[i].a+=1;
		f(x+1);
		e[i].a-=1;
	}
}
int main()
{
	
	freopen("crystal4.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&e[i].a);
	sort(e+1,e+1+n,cmp);
	for(int i=1;i<=n;i++)
		e[i].b=abs(e[i].a-e[i-1].a);
	sort(e+1,e+1+n,cup);
	f(0);
	cout<<maxx;
	return 0;
}
