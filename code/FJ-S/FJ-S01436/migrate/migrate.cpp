#include<bits/stdc++.h>
#define N 2000005
using namespace std;
using ll=long long;
inline ll read()
{
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
	return x*f;
}
int n,L[N],R[N],mxL[N],mxR[N];
ll d,x[N];
vector<int> invL[N],invR[N];
void solve()
{
	n=read(),d=read();
	for(int i=1;i<=n;i++) x[i]=read();
	for(int i=1,j=1;i<=n;i++)
	{
		while(j<=n&&x[j]-x[i]<=d) j++;
		R[i]=j-1;
	}
	for(int i=n,j=n;i>=1;i--)
	{
		while(j>=1&&x[i]-x[j]<=d) j--;
		L[i]=j+1;
	}
	for(int i=1;i<=n;i++) mxL[i]=mxR[i]=1;
	for(int i=1;i<=n-1;i++) if(R[i]>i)
	{
		if(L[R[i]]==i) mxL[R[i]]+=mxL[i];
		else mxL[R[i]]++;
	}
	for(int i=n;i>=2;i--) if(L[i]<i)
	{
		if(R[L[i]]==i) mxR[L[i]]+=mxR[i];
		else mxR[L[i]]++;
	}
	for(int i=1;i<=n;i++) invL[i].clear(),invR[i].clear();
	for(int i=1;i<=n-1;i++) if(i<R[i]) invR[R[i]].push_back(i);
	for(int i=2;i<=n;i++) if(i>L[i]) invL[L[i]].push_back(i);
	ll ans=0;
	for(int i=3;i<n;i++)
	{
		int cntl=0,cntr=0;
		for(int l:invR[i]) if(l!=i-1)
		{
			if(L[i-1]!=l) cntl++;
			else cntl+=mxL[l];
		}
		for(int r:invL[i-1]) if(r!=i)
		{
			if(R[i]!=r) cntr++;
			else cntr+=mxR[r];
		}
		ans+=1ll*cntl*cntr;
	}
	printf("%lld\n",ans);
	return;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c=read(),t=read();
	while(t--) solve();
	return 0;
}

