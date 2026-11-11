#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+6;
int c,t,n,stk[N],L,R;
ll d,x[N];
ll f[N];
int g[N];//min 3
void solve1()
{
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		L=1,R=0;
		f[i]=0,g[i]=1;
		for(int j=i+1;j<=n;j++)
		{
			if(x[j]-x[j-1]>d)break;
			while(L<=R&&x[j]-x[stk[L]]>d)L++;
			while(L<=R&&f[stk[R]]>f[j-1])R--;
			stk[++R]=j-1;
			f[j]=f[stk[L]]+1;
			g[j]=g[stk[L]];
			if(R-L+1>=2)
				if(f[stk[L]]==f[stk[L+1]])
					g[j]=g[j]+g[stk[L+1]];
			if(R-L+1>=3)
				if(f[stk[L]]==f[stk[L+2]])
					g[j]=g[j]+g[stk[L+2]];
			g[j]=min(g[j],3);
			if(g[j]==2)ans++;
			// if(g[j]==2)cout<<i<<' '<<j<<endl;
			// cout<<f[j]<<' ';
		}
		// cout<<endl;
	}
	cout<<ans<<'\n';
	return;
}
bool check2()
{
	for(int i=3;i<=n;i++)
		if(x[i]-x[i-1]!=x[2]-x[1])
			return false;
	return true;
}
void solve2()
{
	ll cha=x[2]-x[1];
	d/=cha;
	if(!d)
	{
		cout<<0<<'\n';
		return;
	}
	ll k=n/2;
	if(k<d)
	{
		cout<<0<<'\n';
		return;
	}
	ll ans=((n-2*k+1)+(n-2*d+1))*(k-d+1)/2;
	cout<<ans<<'\n';
	return;
}
int l[N],r[N],revl[N],revr[N],Ls[N],Rs[N];
void solve3()
{
	for(int i=0;i<=n+1;i++)l[i]=0,r[i]=0,revl[i]=0,revr[i]=0,Ls[i]=0,Rs[i]=0;
	for(int i=1,j=1;i<=n;i++)
	{
		while(j<i&&x[i]-x[j]>d)j++;
		l[i]=j;
	}
	for(int i=n,j=n;i>=1;i--)
	{
		while(j>i&&x[j]-x[i]>d)j--;
		r[i]=j;
	}
	for(int i=1;i<=n;i++)
		if(r[i]>i+1)
			revl[r[i]]++;
	for(int i=1;i<=n;i++)
		if(l[i]<i-1)
			revr[l[i]]++;
	// for(int i=1;i<=n;i++)cout<<revl[i]<<' ';cout<<endl;
	// for(int i=1;i<=n;i++)cout<<revr[i]<<' ';cout<<endl;
	for(int i=1;i<=n;i++)
		if(r[l[i]]==i&&l[i]!=i)
			Ls[i]=Ls[l[i]]+1;
	for(int i=n;i>=1;i--)
		if(l[r[i]]==i&&r[i]!=i)
			Rs[i]=Rs[r[i]]+1;
	// for(int i=1;i<=n;i++)cout<<L[i]<<' ';cout<<endl;
	// for(int i=1;i<=n;i++)cout<<R[i]<<' ';cout<<endl;
	ll ans=0;
	int a,b;
	for(int i=1;i<n;i++)
	{
		a=l[i+1],b=r[i];
		if(a>=i||b<=i+1)continue;
		ans+=1ll*revr[i]*revl[i+1];//nothing more
		if(r[a]==i+1&&l[i]==a)ans+=1ll*revr[i]*Ls[a];
		if(l[b]==i&&r[i+1]==b)ans+=1ll*revl[i+1]*Rs[b];//wrong here
		// cout<<i<<' '<<ans<<endl;
		if(r[a]==i+1&&l[b]==i&&l[i]==a&&r[i+1]==b)ans+=1ll*Ls[a]*Rs[b];
	}
	cout<<ans<<'\n';
}
void solve()
{
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>x[i];
	if(n<=5000)solve1();
	else solve3();
	// else if(check2())solve2();
	return;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--)solve();
	return 0;
}