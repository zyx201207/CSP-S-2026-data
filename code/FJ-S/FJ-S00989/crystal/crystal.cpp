#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N=5e5+5;

int n,m;
int a[N],s[N];

bool chk(int x,int mid)
{
	int sum=s[x-1]-s[mid-1],len=x-mid;
	if(len*a[x]-sum<=m) return 1;
	return 0;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	int mx=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i-1,ans=0;
		while(l<=r){
			int mid=(l+r)>>1;
			if(chk(i,mid)) r=mid-1,ans=mid;
			else l=mid+1;
		}
		if(ans>0) mx=max(mx,i-ans+1);
	}
	cout<<mx;
	return 0;
}

