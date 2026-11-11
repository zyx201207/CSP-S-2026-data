#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[500005],b[500005];
unsigned int cnt,m;
int l,r;
int mid;
bool check(){
	if(b[mid]<=m){
		return 1;
	}
	for(int i=mid+1;i<=n;i++){
		if(b[i]-((i-mid)*(a[i]-a[i-mid+1])+b[i-mid+1])<=m){
			return 1;
		}
	}
	return 0;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		b[i]=(a[i]-a[i-1])*(i-1)+b[i-1];
	}
	l=1,r=n;
	while(l<r){
		mid=(l+r+1)/2;
		if(check()){
			l=mid;
		}else{
			r=mid-1;
		}
	}
	cout<<l<<'\n';
	return 0;
}
/* 
5 8
-3 -1 2 2 7
50134070941278242



























































*/
