#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pll pair<int,int>
const int N=2e5+100,mod=998244353;
int n,m;

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	cin>>n>>m;
	vector<int> a(n+1,0),pre(n+1,0);
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a.begin()+1,a.end());
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i,mid,res=i;
		while(l<=r){
			mid=(l+r)>>1;
			if(a[i]*(i-mid+1)-pre[i]+pre[mid-1]<=m){
				r=mid-1,res=mid;
			}else{
				l=mid+1;
			}
		}
		ans=max(ans,i-res+1);
	}
	cout<<ans<<'\n';
	return 0;
}

