#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int M=5e5+10;
ll qian[M];
ll n,m;
ll a[M];

bool check(int k){
	for(int i=k;i<=n;i++){
		ll cnt=a[i]*(k-1)-(qian[i]-qian[i-k]);
		if(cnt<=m) return true;
	}
	return false;
}

int search(){
	int l=1,r=n,mid;
	while(l<r){
		mid=(l+r+1)>>1;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	return l;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) qian[i]=qian[i-1]+a[i];
	cout<<search();
	return 0;
}

