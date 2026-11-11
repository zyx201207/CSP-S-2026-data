#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;
const ll inf=5e18;
int pre[N],suf[N],lst[N],nxt[N],n;
ll a[N],d;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int _,T;
	cin>>_>>T;
	while(T--)
	{
		cin>>n>>d;
		for(int i=0;i<=n+1;i++) suf[i]=pre[i]=0;
		//nxt[0]=0,lst[n+1]=n+1;
		for(int i=1;i<=n;i++) cin>>a[i];
//		if(T==14)
//		{
//			cerr<<n<<' '<<d<<' '<<endl;
//			for(int i=1;i<=n;i++) cerr<<a[i]-a[1]<<' ';
//		}
		int p=0;
		a[0]=-inf,a[n+1]=inf;
		for(int i=1;i<=n;i++)
		{
			while(a[p]<a[i]-d) p++;
			lst[i]=p; 
		}
		p=n+1;
		for(int i=n;i>=1;i--)
		{
			while(a[p]>a[i]+d) p--;
			nxt[i]=p;
		}
		nxt[0]=lst[0]=0,nxt[n+1]=lst[n+1]=n+1;
		ll ans=0;
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(lst[nxt[i]]==i&&nxt[i]!=i) suf[nxt[i]]+=suf[i];
			if(nxt[i]!=i) suf[nxt[i]]++;
		}
		for(int i=n;i>=1;i--)
		{
			if(nxt[lst[i]]==i&&lst[i]!=i) pre[lst[i]]+=pre[i];
			if(lst[i]!=i) pre[lst[i]]++;
		}
		for(int i=1;i<n;i++)
		{
			int cnt=((lst[i]==lst[i+1]&&nxt[lst[i]]==i+1?suf[lst[i]]:0)+max(0,min(i,lst[i+2])-lst[i+1])),cnt1=((nxt[i]==nxt[i+1]&&lst[nxt[i+1]]==i?pre[nxt[i]]:0)+max(0,nxt[i]-max(i+1,nxt[i-1])));
			//cout<<cnt<<' '<<cnt1<<endl;
			ans+=1ll*cnt*cnt1;
		}
		cout<<ans<<'\n';
	}
}
/*
0 1
10 3
0 3 6 7 8 9 10 11 14 17
*/
