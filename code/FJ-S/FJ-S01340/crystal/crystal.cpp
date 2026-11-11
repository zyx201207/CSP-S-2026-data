#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+5;
int n,m,ans;
int a[maxn],s[maxn];
void solve(){
	ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		int l=i,r=n;
		while(l<r){
			int mid=(l+r+1)/2;
			if(a[mid]*(mid-i+1)-(s[mid]-s[i-1])>m){
				r=mid-1;
			}else{
				l=mid;
			}
		}
		ans=max(ans,l-i+1);
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}
