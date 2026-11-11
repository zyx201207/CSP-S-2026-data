#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long

ll myread()
{
	ll x=0,f=1;
	char ch=getchar();
	while (ch<'0'||ch>'9')
	{
		if (ch=='-') f=-1;
		ch=getchar();
	}
	while (ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
	return x*f;
}

void prin(ll x)
{
	if (x<0)
	{
		putchar('-');
		x=-x;
	}
	if (x>9) prin(x/10);
	putchar(x%10+'0');
}

const int MAXN=2000006;
const int INF=1000000000;

int C;
int n;
ll d;
ll x[MAXN];

int f[MAXN],num[MAXN];
int q[MAXN];

ll calc(int st)
{
	for (int i=st;i<=n;i++) f[i]=INF;
	for (int i=st;i<=n;i++) num[i]=0;
	ll res=0;
	
	f[st]=0; num[st]=1;
	int l=1,r=1;
	q[l]=st;
	for (int i=st+1;i<=n;i++)
	{
		while (l<=r&&x[i]-x[q[l]]>d) l++;
		if (l<=r)
		{
			f[i]=f[q[l]]+1;
			int cnt=0;
			cnt+=num[q[l]];
			if (l+1<=r&&f[q[l]]==f[q[l+1]]) cnt+=num[q[l+1]];
			if (l+2<=r&&f[q[l]]==f[q[l+2]]) cnt+=num[q[l+2]];
			if (cnt>2) num[i]=100;
			else num[i]=cnt;
			if (num[i]==2) res++;
		}
		else break;
		
		while (l<=r&&f[q[r]]>f[i]) r--;
		q[++r]=i;
	}
	return res;
}

void solve()
{
	n=myread(); d=myread();
	for (int i=1;i<=n;i++) x[i]=myread();
	
	if (C==11||C==12)
	{
		if (n==1) prin(0);
		else 
		{
			if (d<2*(x[2]-x[1])) prin(0);
			else prin(max((ll)(0),n-d/(x[2]-x[1])*2+1));
		}
		putchar('\n');
		return;
	}
	
	if (C==13||C==14)
	{
		ll ans=0;
		for (int i=1,j=1,l=1,r=1;i<=n;i++)
		{
			while (j<n&&x[j+1]-x[i]<=d) j++;
			while (j-2>=i&&l<=n&&x[l]-x[j-2]<=d) l++;
			while (j-1>=i&&r<n&&x[r+1]-x[j-1]<=d) r++;
			if (j-i>=2&&j-1>=1&&j-2>=1) ans+=max(0,r-l+1);
		}
		prin(ans);
		putchar('\n');
		return;
	}
	
	ll ans=0;
	for (int i=1;i<=n;i++) ans+=calc(i);
	prin(ans);
	putchar('\n');
	
	return;
}

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	int T;
	C=myread();
	T=myread();
	while (T--)
	{
		solve();
	}
	return 0;
}
