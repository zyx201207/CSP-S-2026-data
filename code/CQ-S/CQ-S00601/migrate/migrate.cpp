#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5,inf=1e18;
int t,n,m,mx,a[N],nxt[N],stk[N],top,bj[N],ans,vst[N];
int la2[N],to1[N],to2[N],sm[N],sm2[N];
vector<int>v[N];
void add(int x)
{
	la2[x]=(bj[x]==2?x:la2[x-1]);
	to1[x]=(bj[x]==3?x:to1[x-1]);
	to2[x]=(bj[x]==3?to1[x-1]:to2[x-1]);
	if(x<top)
	{
		int aa=stk[x+1],bb=stk[x],cc=(x>1?stk[x-1]:mx);
		int l=bb+1,r=cc,mid;
		while(l<=r)
		{
			mid=(l+r)/2;
			if(a[mid]-a[bb-1]<=m) l=mid+1;
			else r=mid-1;
		}
		int w=l;
		sm[x]=sm[x-1]+(cc-w+1);
		if(x+1==top||a[bb-1]-a[aa-1]>m)
		{
			l=bb+1,r=cc;
			while(l<=r)
			{
				mid=(l+r)/2;
				if(a[mid]-a[max(aa,bb-2)]<=m) l=mid+1;
				else r=mid-1;
			}
			sm2[x]=sm2[x-1]+max(0ll,w-l);
		}
		else sm2[x]=sm2[x-1];
	}
	else sm[x]=sm[x-1],sm2[x]=sm2[x-1];
}
void dfs(int x)
{
	stk[++top]=x,vst[x]=1;
	int lst;
	if(top>3)
	{
		lst=bj[top-2];
		int aa=stk[top],bb=stk[top-1],cc=stk[top-2],dd=stk[top-3];
		if(a[dd]-a[cc-1]>m) bj[top-2]=1;
		else if(a[dd]-a[cc-2]<=m) bj[top-2]=2;
		else if(a[cc-1]-a[bb-1]<=m) bj[top-2]=2;
		else bj[top-2]=3;
		add(top-2);
	}
	if(top>=3)
	{
		int aa=stk[top],bb=stk[top-1],cc=stk[top-2];
		if(a[cc]-a[bb-1]>m) bj[top-1]=1;
		else if(bb-2>=aa&&a[cc]-a[bb-2]<=m) bj[top-1]=2;
		else bj[top-1]=3;
		add(top-1);
	}
	bj[top]=0,add(top);
	int l=to1[top],r=max(la2[top],to2[top]);
	l=max(0ll,l-1),r=max(0ll,r-1),l=max(l,r);
	int nw=top,as=0,as2=0;
	ans+=sm2[top]-(l?sm2[l]:0);
	if(l>=r) ans+=(l?sm[l]:0)-(r?sm[r]:0);
	for(auto i:v[x])
	{
		dfs(i);
		if(top>2) add(top-2);
		if(top>1) add(top-1);
		add(top);
	}
	if(top>3) bj[top-2]=lst;if(top>=3) bj[top-1]=0;
	top--;
}
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>t>>t;
	while(t--)
	{
		cin>>n>>m,ans=0;
		for(int i=1;i<=n;i++) v[i].clear(),vst[i]=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		int nw=1;
		for(int i=1;i<=n;i++){while(nw<=n&&a[nw]-a[i]<=m) nw++;nxt[i]=nw-1;}
		for(int i=1;i<n;i++) if(nxt[i]>i) v[nxt[i]].push_back(i);
		for(int i=n;i;i--) if(!vst[i]) mx=i,dfs(i);
		cout<<ans<<'\n';
	}
	return 0;
}
