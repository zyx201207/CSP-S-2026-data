#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=500005;
int n,m,a[maxn],l=1,ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		a[i]+=a[i-1];
	}
	for(int i=1;i<=n;i++){
		while((a[i]-a[i-1])*(i-l+1)-(a[i]-a[l-1])>m){
			l++;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
} 
