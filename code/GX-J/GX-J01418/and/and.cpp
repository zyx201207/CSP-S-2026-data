#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
struct node
{
	int tot,s;
}a[N];
int n,m,c[N],cnt=1,ans;
map<int,int> mp;
map<int,bool> fi;
bool cmp(node x,node y)
{
	return x.s>y.s;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		mp[c[i]]++;
		fi[c[i]]=true;
	}
	for(int i=1;i<=n;i++)
	{
		if(fi[c[i]]==true)
		{
			node x;
			x.s=c[i];
			x.tot=mp[c[i]];
			fi[c[i]]=false;
			a[cnt++]=x;
		}
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=cnt;i++)
	{
		int s=m,now=a[i].s,t=i;
		if(a[i].tot>=m)
		{
			ans=max(ans,a[i].s);
			break;
		}
		while(s>0)
		{
			s-=a[t].tot;
			now=now&a[t].s;
			t--;
		}
		ans=max(ans,now);
	}
	cout<<ans;
	return 0;
}
