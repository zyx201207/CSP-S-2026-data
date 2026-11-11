#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[200010],tree[800010],ans;
void pushup(int u)
{
	tree[u]=tree[u*2]&tree[u*2+1];
	return;
}
void init(int u,int l,int r)
{
	if(l==r)
	{
		tree[u]=a[l];
		return;
	}
	int mid=(l+r)/2;
	init(u*2,l,mid);
	init(u*2+1,mid+1,r);
	pushup(u);
	return;
}
int query(int u,int l,int r,int sl,int sr)
{
	if(r<sl||l>sr) return (1<<30)-1;
	if(sl<=l&r<=sr) return tree[u];
	int mid=(l+r)/2,ad=(query(u*2,l,mid,sl,sr)&query(u*2+1,mid+1,r,sl,sr));
	return ad;	
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	init(1,1,n);
	for(int i=1;i+m-1<=n;i++) ans=max(ans,query(1,1,n,i,i+m-1));
	cout<<ans;
}
/*
tan chi she     wei shen me hui ka si   56 wo jing li la
*/
