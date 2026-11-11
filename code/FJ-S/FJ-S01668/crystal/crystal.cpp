#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,ans=-1;
long long m,a[N],pre[N];
int search(int l,int r,int x)
{
	if(l>=r) return r;
	int mid=(l+r)/2;
	if((a[x]*(x-mid)-(pre[x-1]-pre[mid-1]))<=m) return search(l,mid,x);
	return search(mid+1,r,x);
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	pre[0]=0;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		pre[i]=pre[i-1]+a[i];
	for(int i=2;i<=n;i++)
		ans=max(ans,i-search(1,i-1,i)+1);
	cout<<ans;
	return 0;
}

