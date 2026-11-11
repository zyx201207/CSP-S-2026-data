#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+5;
int n,num;
ll m;
ll a[N];
ll qzh[N];
bool Check(int ans){
	for(int i=1;i+ans-1<=n;i++){
		if(qzh[i+ans-1]-qzh[i-1]+m>=a[i+ans-1]*ans) return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) qzh[i]=qzh[i-1]+a[i];
	int l=1,r=n;
	while(l<r){
		int mid=((l+r)>>1)+1;
		if(Check(mid)) l=mid;
		else r=mid-1;
	}
	cout<<l;
	return 0;
}
