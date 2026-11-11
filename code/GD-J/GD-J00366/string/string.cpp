#include<bits/stdc++.h>
using namespace std;
int n;
int a[200003];
char b[200003];
long long l[200003];
#define r(x) l[x]+a[x]-1
long long rf(long long f[],long long fs,int l,int r)
{
	while(l!=r)
	{
		int mid=(l+r+1)>>1;
		if(f[mid]<=fs)l=mid;
		else r=mid-1;
	}
	return l;
}
long long ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	long long x=1;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),cin>>b[i],
		l[i]=x,x+=a[i];
	--x;
	long long l1=(x+1)/2+1;
	for(int i=rf(l,(x+1)/2+1,1,n),
		j=rf(l,x-(x+1)/2,1,n);i<=n;i++)
	{
		for(++j;l1<=r(i);)
		{
			--j;
			long long mr=min(x+1-l[j],r(i));
			ans+=(mr-l1+1)*(b[j]!=b[i]);
			l1=mr+1;
		}
	}
	cout<<ans;
	return 0;
}
/*
7
6 a
1 b
1 c
1 d
1 e
1 f
1 g

3
2 a
2 b
1 c

2
2 a
3 a

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b


*///
