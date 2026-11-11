#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500010];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int s=0;
	int l=1;
	int ans=0;
	for(int i=2;i<=n;i++){
		s+=(a[i]-a[i-1])*(i-l);
		while(s>m){
			s-=a[i]-a[l];
			l++;
		}
		ans=max(ans,(i-l+1));
	}
	cout<<ans<<'\n';
	return 0;
} 
