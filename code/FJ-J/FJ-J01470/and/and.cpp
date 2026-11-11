#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],k[200010][40],maxn,ans=2147483647,sum[40],cnt,ch[40];
struct num
{
	int a,beg,fir,id;
}s[200010];
int lowbit(int x)
{
	int q=x&(-x),sum=0;
	while(q)
	{
		sum++;
		q>>=1;
	}
	return sum;
}
bool operator <(num a,num b)
{
	if(a.fir==b.fir) return a.beg>b.beg;
	return a.fir>b.fir;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i].a=a[i];
		s[i].id=i;
		while(a[i])
		{
			int l=lowbit(a[i]);
			k[i][l]=1;
			maxn=max(maxn,l);
			a[i]-=(a[i]&(-a[i]));
		}
	}
	for(int j=1;j<=maxn;j++)
	{
		for(int i=1;i<=n;i++) sum[j]+=k[i][j];
		if(sum[j]>=m) ch[++cnt]=j;
	}
	for(int i=1;i<=n;i++)
	{
		int sum=0;
		bool flag=1;
		for(int j=cnt;j>=1;j--)
		{
			if(flag&&k[i][ch[j]]==0) continue;
			else if(k[i][ch[j]]==0) break;
			if(!s[i].fir) s[i].fir=ch[j];
			sum++;
			flag=0;
		}
		s[i].beg=sum;
	}
	sort(s+1,s+n+1);
	int cnt=0;
	for(int i=1;i<=n&&cnt<=m;i++)
	{
		if(k[s[1].id][s[i].fir]==1) ans&=s[i].a,cnt++;
	}
	if(cnt<m) cout<<0;
	else cout<<ans;
	return 0;
}
