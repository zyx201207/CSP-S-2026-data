#include<bits/stdc++.h>
using ll=long long;
using namespace std;
constexpr int N=2e6+5;
int n, nxt[N];
ll d, a[N];
int mn[5005][5005], f[5005][5005], t[5005];
ll read()
{
	ll x=0, fuhao=1;
	char ch=getchar();
	while(ch<'0' || ch>'9')
	{
		if(ch=='-') fuhao=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9') x=10*x+ch-'0', ch=getchar();
	return x*fuhao;
}
void work()
{
	n=read();
	d=read();
	for(int i=1; i<=n; i++)
	{
		a[i]=read();
	}
	nxt[n]=n;
	for(int i=n-1; i; i--)
	{
		nxt[i]=nxt[i+1];
		while(a[nxt[i]]-a[i]>d) nxt[i]--;
	}
	ll res=0;
	for(int i=1; i<n; i++)
	{
		vector<int> s;
		int now=i;
		do
		{
			s.push_back(now);
			now=nxt[now];
			if(now==nxt[now]) break;
		}while(now!=n);
		s.push_back(n);
		for(int j=1; j<=n; j++) f[i][j]=0, t[j]=0;
		f[i][i]=1;
		for(int j=0; j<(int)s.size(); j++)
		{
			int bj=0;
			for(int k=(j?s[j-1]+1:i); k<=s[j]; k++)
			{
				t[k]+=t[k-1];
				f[i][k]+=t[k];
				f[i][k]=min(f[i][k], 3);
				t[nxt[k]+1]-=f[i][k];
				t[s[j]+1]+=f[i][k];
				if(f[i][k]==2) res++;
				if(f[i][k]<=2) bj=1;
			}
			if(!bj) break;
		}
	}
	cout<<res<<'\n';
}
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, T;
	c=read();
	T=read();
	while(T--) work();
}
