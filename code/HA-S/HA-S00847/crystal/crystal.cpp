#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans;
int a[1000001];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+1+n);
	int l=1,r=1,sum=0;
	while(r<n){
		if(sum+(a[r+1]-a[r])*(r-l+1)<=m){
			sum+=(a[r+1]-a[r])*(r-l+1);
			r++;
			ans=max(ans,r-l+1);
		}else{
			if(l==r){
				l++,r++;
				continue;
			}sum-=(a[r]-a[l]);
			l++;
		}
	}cout<<ans;
}
