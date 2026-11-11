#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans;
int a[500005];
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
	sort(a+1,a+n+1);
	int t=0;
	for(int l=1,r=1;r<=n;r++){
		t+=a[r];
		while(a[r]*(r-l+1)-t>m){
			t-=a[l],l++;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
