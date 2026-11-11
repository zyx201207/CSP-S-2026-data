#include<bits/stdc++.h>

using namespace std;

const int N=5e5+5;
long long m,a[N],cha[N],pre[N],pre_d[N];
long long n,ans;
int find(int x)
{
	int l=1,r=x;
	int key=-1;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(a[x]*(x-mid)-(pre[x-1]-pre[mid-1])<=m) {
			key=mid;
			r=mid-1;
		}else l=mid+1;
	}
	return key;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		pre[i]=pre[i-1]+a[i];
	for(int i=1;i<=n;i++) {
		int k=find(i);
		if(k==-1) continue;
		ans=max(1LL*i-k+1,ans);
	}
	cout<<ans;
	return 0;
}
