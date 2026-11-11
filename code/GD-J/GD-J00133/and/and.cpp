#include<bits/stdc++.h>
using namespace std;
long long n,m,a[235002],b[235002][35],l[235002],w[35],s;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]),l[i]=1;
	w[0]=1;
	for(int i=1;i<=32;i++) w[i]=w[i-1]*2;
	for(int i=1;i<=n;i++)
		for(int j=32,t=a[i];j>=0;j--)
			if(t>=w[j]) t-=w[j],b[i][j]=1;
	for(int t=32;t>=0;t--)
	{
		int cnt=0;
		for(int i=1;i<=n;i++) cnt+=b[i][t]*l[i];
		if(cnt>=m)
		{
			for(int i=1;i<=n;i++)
				if(!b[i][t]) l[i]=0;
			s|=w[t];
		}
	}
	printf("%lld",s);
	return 0;
}
