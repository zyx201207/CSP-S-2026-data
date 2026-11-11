#include<bits/stdc++.h>
#define ll long long
using namespace std;
int C,T,n,p,cnt,lm[2000100],rm[2000100];
ll a[2000100],d,s[2000100],ans,ls[2000100],rs[2000100];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>C>>T;
	while(T)
	{
		T--;
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			ls[i]=rs[i]=1;
			lm[i]=rm[i]=0;
		}
		int l=1,r=n,tr;
		for(int i=1;i<=n;i++)
		{
		  while(a[i]-a[l]>d)
		    l++;
		  lm[i]=l;
		}
		for(int i=n;i>=1;i--)
		{
		  while(a[r]-a[i]>d)
		    r--;
		  rm[i]=r;
		}
		for(int i=1;i<=n;i++)
		{
		  if(rm[lm[i]]-lm[rm[i]]==0 && rm[lm[i]]<rm[i])
		    ls[rm[i]]+=ls[i];
		}
		for(int i=n;i>=1;i--)
		{
		  if(rm[lm[i]]-lm[rm[i]]==0 && rm[lm[i]]<rm[i])
		    rs[lm[i]]+=rs[i];
		}
		r=n;
		for(int i=n;i>=1;i--)
		{
			while(rm[i]-lm[r]<1)
			  r--;
			tr=r;
			while(rm[i]-lm[tr]==1)
			{
			  if(rm[i]<tr&&lm[tr]>i)
			    ans+=(ls[rm[i]])*(rs[lm[tr]]);
			  tr--;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

