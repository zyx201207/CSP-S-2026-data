#include<bits/stdc++.h>
using namespace std;

int n,m,lst[500005],fl[500005],a[500005],sum[500005],dif[500005];
struct dd{
	int l,r;
}g[500005];

bool cmp(dd f,dd s)
{
	return f.l<s.l;
}

void calc(int l,int r)
{
	memset(lst,0,sizeof(lst));
	for(int i=1;i<=m;i++) fl[i]=0;
	for(int i=l;i<=r;i++) 
	{
		fl[a[i]]=1;
	}
	int h=0;
	for(int i=l;i<=r;i++) 
	{
		if(lst[a[i]])
		{
			g[++h]={lst[a[i]],i};	
		}
		lst[a[i]]=i;
	}
	sort(g+1,g+h+1,cmp);
	int ff=g[1].r,sf=1,ww=h;
	while(sf<h)
	{
		for(int kk=sf+1;kk<=h;kk++) 
		{
			if(g[kk].l<ff)
			{
				g[kk]={0x3f3f3f3f,0x3f3f3f3f};
				ww--;
			}
			else 
			{
				ff=g[kk].r,sf=kk;
				break;
			}
		}	
	}
	sort(g+1,g+h+1,cmp);
	for(int i=1;i<=ww;i++)
	{
		for(int j=g[i].l+1;j<g[i].r;j++)
		{
			fl[a[j]]=0;
		}
	}
	fl[a[r]]=1; 
	for(int i=1;i<=m;i++) sum[i]+=fl[i];
}

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];	
	}
	for(int i=1;i<=n;i++)
	{
		calc(i,n);
	}
	for(int i=1;i<=m;i++) cout<<sum[i]<<' ';
	return 0;
} 
