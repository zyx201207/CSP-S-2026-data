#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500005];
int pre[500005];
bool check(int len){
	for(int i=len;i<=n;i++){
		int j=i-len+1;
		if(pre[i]-pre[j-1]-(a[i]-a[j-1])*(j-1)<=m){
			return 1;
		}
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+(i-1)*(a[i]-a[i-1]);
	}
	int l=0,r=n+1;
	while(r-l>1){
		int mid=(r+l)>>1;
		if(check(mid)){
			l=mid;
		}else{
			r=mid;
		}
	}
	cout<<l;
	return 0;
}
