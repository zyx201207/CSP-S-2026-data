#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int a[N];
int n,m;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=1,r=1,s=0,ans=1;
	int last=0;
	while(r<=n){
		s+=(a[r]-a[r-1])*(r-l);
		r++;
		while(s>m)s-=a[r]-a[l++];
		ans=max(ans,r-l);
	}
	cout<<ans;
	return 0;
}
