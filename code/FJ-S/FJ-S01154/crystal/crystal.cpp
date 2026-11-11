#include<bits/stdc++.h>
using namespace std;
typedef long long lzx;
const int N=5e5+10;
lzx n,m;
lzx a[N],diff[N],pre[N];
lzx init(int x){
	lzx sum=0;
	for(int i=1;i<x;i++){
		sum+=diff[i]*i;
	}
	return sum;
}
bool check(int len){
	lzx sum=init(len);
	if(sum<=m){
		return true;
	}
	for(int i=len;i<n;i++){
		sum=sum-(pre[i]-pre[i-len+1])+diff[i]*(len-1);
		if(sum<=m){
			return true;
		}
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		diff[i-1]=a[i]-a[i-1];
		pre[i]=pre[i-1]+diff[i-1];
	}
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;
		}
		else r=mid-1;
	}
	cout<<r;
	return 0;
}
