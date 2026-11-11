#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=500010;
int n,m,a[N],s[N];
signed main(){
	freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i-1,res=0;
		while(l<=r){
			int mid=(l+r)>>1;
			if(a[i]*(i-mid)-s[i-1]+s[mid-1]<=m) res=mid,r=mid-1;
			else l=mid+1;
		}
		//~ cerr<<i<<' '<<res<<'\n';
		ans=max(i-res+1,ans);
	}cout<<ans;
}
