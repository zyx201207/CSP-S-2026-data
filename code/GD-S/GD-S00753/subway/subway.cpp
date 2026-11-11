#include<bits/stdc++.h>
using namespace std;
long long minn[500005],c,n,m,d,q,w[500005],l,t,a[500005],qs,qe;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
	memset(minn,127,sizeof(minn));
	for(int i=1;i<=n;i++) 
	{
		cin>>l;
		for(int j=1;j<=l;j++) 
		{
			scanf("%lld%lld",&a[i],&t);
			minn[a[i]]=min(minn[a[i]],t);
		}
	}
	for(int i=1;i<=q;i++)
	{
		scanf("%lld%lld",&qs,&qe);
		printf("%lld\n",w[qs]+w[qe]);
	}
	return 0;
}
