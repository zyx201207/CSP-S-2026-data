#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back

inline int read()
{
	int x;
	cin>>x;
	return x;
}

int sub;
int n,d;
int a[2000010];

struct node
{
	int l,r,num;
};

inline bool check(int l,int r)
{
	int sum=0,L=l;
	vector<node>b;
	for(int i=l;i<r;i++)
	{
		if(sum+(a[i+1]-a[i])<=d)
			sum+=(a[i+1]-a[i]);
		else
		{
			b.pb({L,i,sum});
			if(a[i+1]-a[i]>d)
				return 0;
			sum=a[i+1]-a[i],L=i;
		}
	}
	b.pb({L,r,sum});
	int cnt=0;
	for(int i=1;i<b.size();i++)
	{
		if(b[i].num+(a[b[i].l]-a[b[i].l-1])<=d)
		{
			if(cnt>=1)
				return 0;
			cnt++;
			int p=b[i].l,js=0,SUM=b[i].num;
			for(int k=1;;k++,p--)
			{
				if(p-1<=b[i-1].l)
					break;
				if(SUM+a[p]-a[p-1]<=d)
					js++,SUM+=(a[p]-a[p-1]);
				else
					break;
			}
			if(js!=1)
				return 0;
		}
	}
	return cnt==1;
}

inline void work()
{
	n=read(),d=read();a[n+1]=0;
	for(int i=1;i<=n;i++)
		a[i]=read();
	int ans=0;
	if(n==1)
	{
		cout<<0<<'\n';
		return ;
	}
	if(sub==11||sub==12)
	{
		int len=d/(a[2]-a[1]);
		if(len<=1)
		{
			cout<<0<<'\n';
			return ;
		}
		for(int i=1;i<=n;i++)
			if(i+len*2-1<=n)
				ans++;
		cout<<ans<<'\n';
		return ;
	}
	if(sub==13||sub==14)
	{
		cout<<0<<'\n';
		return ;
	}
	if(sub<=10)
	{
		for(int l=1;l<=n;l++)
			for(int r=l+1;r<=n;r++)
				ans+=check(l,r);
	}
	cout<<ans<<'\n';
}

signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	sub=read();int T=read();
	while(T--)
		work();
	return 0;
}
