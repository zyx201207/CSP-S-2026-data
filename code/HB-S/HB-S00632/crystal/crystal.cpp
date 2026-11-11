#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,as;
int a[5000005];
int fr[5000005];
int check(int l,int r,int ch){
	return ch*(r-l+1)-fr[r]+fr[l-1]<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		fr[i]=fr[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		int l=1,r=i-1;
		while(l<r){
			int mid=(l+r-1)/2;
			if(check(mid,i-1,a[i])){
				r=mid;
			}
			else{
				l=mid+1;
			}
		}
		as=max(as,i-r+1);
	}
	cout<<as;
	return 0;
}
