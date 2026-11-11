#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 5e5+5;
int n;
LL a[N],m;
bool check(int num){
	LL cnt = 0;
	for(int i=1;i<num;i++){
		cnt+=a[i];
	}
	for(int i = num;i<=n;i++){
		if(a[i]*(num-1)-cnt<=m) return true;
		cnt-=a[i-num+1];
		cnt+=a[i];
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int l = 1,r = n,mid;
	while(l<r){
		mid = (l+r+1)>>1;
		if(check(mid)){
			l = mid;
		}else{
			r = mid-1;
		}
	}
	/**
	LL cnt = 0;
	for(int i=1;i<l;i++){
		cnt+=a[i];
	}
	for(int i = l;i<=n;i++){
		if(a[i]*(l-1)-cnt<=m){
			cout<<i<<'\n';
		}
		cnt-=a[i-l+1];
		cnt+=a[i+1];
	}
	**/
	cout<<l;
	return 0;
}
