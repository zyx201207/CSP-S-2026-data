#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500010],s[500010],ans;
bool check(int x,int k){
	return (s[x]-s[x-k+1]-(x-k-1)*(a[x]-a[x-k+1]))<=m;
}
int find(int x){
	int l=1,r=x;
	int mid;
	while(l<=r){
		mid=l+(r-l)/2;
		if(check(x,mid)){
			r=mid-1;
		}else{
			l=mid+1;
		}
//		cout<<mid;
	}
	return x-l+1;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		s[i]=(a[i]-a[i-1])*(i-1)+s[i-1];
//		cout<<s[i]<<' ';
	}
	for(int i=2;i<=n;i++){
		ans=max(ans,find(i));
	}
	cout<<ans;
	return 0;
}//5 5 1 2 4 8 9
