#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n,ans;
ll m,a[500005],c[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int l=1,r=1;
	ll tmp=0;
	while(l<=r&&r<n){
		if(tmp+(a[r+1]-a[r])*(r-l+1)<=m){
			if(r-l+2>ans){
				ans=r-l+2;
			}
			tmp+=(a[r+1]-a[r])*(r-l+1);
			r++;
		}else{
			tmp-=a[r]-a[l];
			l++;
		}
	}
	cout<<ans<<'\n';
	return 0;
}
