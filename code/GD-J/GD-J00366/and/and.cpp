#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int h[200005],k;
int H[200005],K;
bool b[200005][32];
int ans;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),h[i]=i;
//	cerr<<"1\n";
//	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		for(int j=0,s=a[i];s>0;j++,s>>=1)
			b[i][j]=s%2;//,cerr<<s<<"\n";
//	cerr<<"2\n";
	k=n;
	for(int i=30,as=1073741824;i>=0;i--,as>>=1)
	{
		K=0;
		for(int j=1;j<=k;j++)
			if(b[h[j]][i])
				H[++K]=h[j];
		if(K>=m)
		{
			ans+=as;
			k=K;
			for(int j=1;j<=k;j++)
				h[j]=H[j];
		}
	}
	cout<<ans;
	return 0;
}
/*
4 2
3 15 12 12

*///
