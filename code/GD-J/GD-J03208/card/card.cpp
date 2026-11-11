#include<bits/stdc++.h>
#define int long long
#define fre freopen("card.in","r",stdin),freopen("card.out","w",stdout)
using namespace std;
const int MAXN=5e5+34;
int n,m,ans[MAXN],a[MAXN],b[MAXN],c[MAXN],tree[MAXN*6],lazy[MAXN*6];
void pushdown(const int x)
{
	if(lazy[x]!=0)
	{
		lazy[x*2]=max(lazy[x*2],lazy[x]),lazy[x*2+1]=max(lazy[x*2+1],lazy[x]);
		tree[x*2]=max(tree[x*2],lazy[x]),tree[x*2+1]=max(tree[x*2+1],lazy[x]);
		lazy[x]=0;
	}
}
void change(const int x,const int l,const int r,const int L,const int R,const int val)
{
	if(L>R) return;
	if(L<=l&&r<=R) tree[x]=max(tree[x],val),lazy[x]=max(lazy[x],val);
	else
	{
		pushdown(x);
		if(L<=(l+r)/2) change(x*2,l,(l+r)/2,L,R,val);
		if(R>(l+r)/2) change(x*2+1,(l+r)/2+1,r,L,R,val);
	}
}
int lookfor(const int x,const int l,const int r,const int tot)
{
	if(l==r) return tree[x];
	pushdown(x);
	if(tot<=(l+r)/2) return lookfor(x*2,l,(l+r)/2,tot);
	return lookfor(x*2+1,(l+r)/2+1,r,tot);
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	fre,cin>>n>>m;
	for(int i=1;i<=n;b[a[i]]=i,i++)
	{
		cin>>a[i];
		if(b[a[i]]>0) change(1,1,n,b[a[i]]+1,i,b[a[i]]);
	}
	if(n<=5000)
	{
		for(int i=1;i<=n;i++) b[a[i]]=0;
		for(int i=1;i<=n;i++,c[0]=0)
		{
			for(int j=1;j<=n;j++) b[a[j]]=c[j]=0;
			for(int j=i;j<=n;j++)
			{
				if(b[a[j]]==0||b[a[j]]>c[0]) c[++c[0]]=a[j],b[a[j]]=c[0];
				else c[0]=b[a[j]];
			}
			set<int> st;st.clear();
			for(int j=1;j<=c[0];j++) st.insert(c[j]);
			while(!st.empty()) ans[(*st.begin())]++,st.erase(st.begin());
		}
	}
	else for(int i=1;i<=n;i++) ans[a[i]]+=i-lookfor(1,1,n,i);
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
