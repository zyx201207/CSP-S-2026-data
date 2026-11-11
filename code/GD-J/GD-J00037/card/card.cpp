#include<bits/stdc++.h>
using namespace std;

int n,m;
int po[500100],ch[500100],ans[500100];
int mp[300100],md[300100];
int vc[2000100],pm[2000100];
struct dd{
	int a,b;
};
dd wp[500100];
void insert(int a,int b,int l=1,int r=n,int x=1)
{
	//cout<<l<<" "<<r<<"\n";
	if(a<=l&&b>=r)
	{
		vc[x]=1;
		pm[x]=1;
		//cout<<vc[x]<<" "<<x<<"\n";
		return;
	}
	int mid=l+r>>1;
	if(a<=mid)
	{
		insert(a,b,l,mid,x*2);
	}
	if(b>mid)
	{
		insert(a,b,mid+1,r,x*2+1);
	}
}
int find(int a,int l=1,int r=n,int x=1)
{
	//cout<<l<<" "<<r<<"\n";
	if(l==a&&r==a)
	{
		// cout<<x<<"\n";
		return vc[x];
	}
	int mid=l+r>>1;
	if(pm[x])
	{
		vc[x*2]=pm[x];
		vc[x*2+1]=pm[x];
		pm[x*2]=pm[x];
		pm[x*2+1]=pm[x];
	}
	if(a<=mid)
	{
		return find(a,l,mid,x*2);
	}
	if(a>mid)
	{
		return find(a,mid+1,r,x*2+1);
	}
}
bool cmp(dd a,dd b)
{
	if(a.b==b.b)
	{
		return a.a>b.a;
	}
	return a.b<b.b;
}

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>po[i];
	}
	ch[n]=n;
	mp[po[n]]=n;
	for(int j=n-1;j>=1;j--)
	{
		//cout<<j<<" "<<po[j]<<":";
		ch[j]=ch[j+1]-1;
		if(mp[po[j]]!=0&&find(mp[po[j]])==0)
		{
			//cout<<find(mp[po[j]])<<" "<<"Yes:"<<j<<"~"<<mp[po[j]]-1;
			insert(j,mp[po[j]]-1);
			//cout<<"Hi";
			for(int t=mp[po[j]]-1;t>=j;t--)
			{
				if(ans[t]==0)
				{
					ans[t]=ch[t]-j;
				}
			}
		}
		else
		{
			mp[po[j]]=j;
		}
		//cout<<"\n";
		/*
		4 3
		1 2 1 3
		*/
	}
	for(int i=n;i>=1;i--)
	{
		if(ans[i]==0)
		{
			ans[i]=i;
		}
		//cout<<po[i]<<" "<<ans[i]<<"\n";
		wp[i]={ans[i],po[i]};
	}
	sort(wp+1,wp+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		if(md[wp[i].b]==0)
		{
			cout<<wp[i].a<<" ";
			md[wp[i].b]=1;
		}
	}
	return 0;
}
/*
*/
