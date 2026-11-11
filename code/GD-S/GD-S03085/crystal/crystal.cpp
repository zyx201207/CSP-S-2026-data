#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
long long n,m,a[N],ans,l=1,r=1e6;
bool check(int x){
	long long sum=0;
	for (long long i=1;i<=x;i++){
		sum+=a[i];
	}
	for (long long i=x;i<=n;i++){
		if (a[i]*x-sum<=m)return 1;
		sum+=a[i+1];
		sum-=a[i-x+1];
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >>n>>m;
	for (long long i=1;i<=n;i++){
		cin >>a[i];
	}
	sort(a+1,a+1+n);
	while(l<=r){
		long long mid=(l+r)/2;
		if (check(mid)){
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout <<r;
	return 0;
}
