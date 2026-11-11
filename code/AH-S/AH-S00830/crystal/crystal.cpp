#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int a[N];
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	int n,m,cnt=0,ans=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n,cmp);
	int l=1,r=1;
	while(r<=n){
		r++,cnt+=a[l]-a[r];
		if(cnt<=m) ans=max(ans,r-l+1);
		while(cnt>m&&l<r) cnt=cnt-(a[l]-a[l+1])*(r-l),l++;
	}
	ans=max(ans,r-l);
	cout<<ans;
	return 0;
}
