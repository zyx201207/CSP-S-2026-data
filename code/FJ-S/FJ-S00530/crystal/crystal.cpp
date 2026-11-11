#include<bits/stdc++.h> 
using namespace std;
long long n,m,a[500010];
long long check(long long t){
	long long cnt=1e18;
	for(int i=1;i<=n-t+1;i++){
		long long k=0;
		for(int j=i+1;j<i+t;j++){
			k+=a[i]-a[j];
		}
		cnt=min(cnt,k);
	}
	return cnt;
}
long long find(){
	long long l=1,r=n,mid;
	while(l<r){
		mid=(l+r+1)/2;
		long long p=check(mid);
		if(p<=m){
			l=mid;
			if(p==m){
				return l;
			}
		}else{
			r=mid-1;
		}
	}
	return l;
}
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	cout<<find();
	return 0;
}
