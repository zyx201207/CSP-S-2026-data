#include<bits/stdc++.h>
using namespace std;
const int N=2000005;
#define ll long long
ll x[N];
int lst[N],nxt[N];
ll lcnt[N],rcnt[N];
ll lcnt2[N],rcnt2[N];
ll lcnt3[N],rcnt3[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int id,T;
	scanf("%d%d",&id,&T);
	while(T--)
	{
		int n;
		ll d;
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++) scanf("%lld",&x[i]);
		lst[0]=1;
		for(int i=1;i<=n;i++)
		{
			lst[i]=lst[i-1];
			while(x[i]-x[lst[i]]>d) lst[i]++;
		}
		for(int i=1;i<=n;i++)
		{
			if(lst[i]==i) lst[i]=-1;
		}
		nxt[n+1]=n;
		for(int i=n;i>=1;i--)
		{
			nxt[i]=nxt[i+1];
			while(x[nxt[i]]-x[i]>d) nxt[i]--;
		}
		for(int i=1;i<=n;i++)
		{
			if(nxt[i]==i) nxt[i]=-1;
		}
		for(int i=1;i<=n;i++) lcnt[i]=rcnt[i]=lcnt2[i]=rcnt2[i]=lcnt3[i]=rcnt3[i]=0;
		for(int i=1;i<=n;i++) if(lst[i]>=0)
		{
			rcnt3[lst[i]]++;
			if(lst[i]<i-1) rcnt2[lst[i]]++;
		}
		for(int i=1;i<=n;i++) if(nxt[i]>=0)
		{
			lcnt3[nxt[i]]++;
			if(nxt[i]>i+1) lcnt2[nxt[i]]++;
		}
//		for(int i=1;i<=n;i++) cout << lst[i] << ' ';
//		cout << endl;
//		for(int i=1;i<=n;i++) cout << nxt[i] << ' ';
//		cout << endl;
		for(int i=1;i<=n;i++)
		{
			lcnt[i]=lcnt3[i];
			if(lst[i]>=0) if(nxt[lst[i]]==i) lcnt[i]+=lcnt[lst[i]];
		}
		for(int i=n;i>=1;i--)
		{
			rcnt[i]=rcnt3[i];
			if(nxt[i]>=0) if(lst[nxt[i]]==i) rcnt[i]+=rcnt[nxt[i]];
		}
		ll ans=0;
		for(int i=1;i<n;i++)
		{
			ans+=rcnt2[i]*lcnt2[i+1];
//			cout << i << ' ' << i+1 << ' ' << rcnt2[i]*lcnt2[i+1] << endl;
			int x=lst[i],y=nxt[i+1];
			if(x>=0 && nxt[x]==i+1)
			{
				ans+=rcnt2[i]*lcnt[x];
			}
			if(y>=0 && lst[y]==i)
			{
				ans+=lcnt2[i+1]*rcnt[y];
			}
			if(x>=0 && y>=0 && lst[y]==i && nxt[x]==i+1)
			{
//				cout << i << ' ' << i+1 << "  " << lcnt[x]-1 << ' ' << rcnt[y]-1 << endl;
				ans+=lcnt[x]*rcnt[y];
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
