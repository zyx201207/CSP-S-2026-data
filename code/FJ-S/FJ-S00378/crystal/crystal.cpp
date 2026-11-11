#include<bits/stdc++.h>
#define int long long
#define N 500005
using namespace std;
int a[N];
int b[N];
void solve(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>b[i];
	sort(b+1,b+1+n);
	int ans=1;
	for(int i=1;i<=n;i++){
		int x=b[i];
		a[i]+=a[i-1]+x;
		int l=1,r=i;
		while(l<r){
			int mid=(l+r)>>1;
			int check=a[i]-a[mid-1];
			if((i-mid+1)*x-check<=m)r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-r+1);
	}
	cout<<ans;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--)solve();
	return 0;
}
