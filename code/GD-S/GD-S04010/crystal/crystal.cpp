#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N];
long long sum[N];
long long  n,m;
bool check(long long  mid){
	for(int i=mid;i<=n;i++){
		long long t=sum[i]-sum[i-mid];
		long long t1=mid*a[i];
		long long t2=t1-t;
		if(t2<=m) return 1;
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=a[i]+sum[i-1];
	}
	long long  l=1,r=n;
	while(l<r){
		long long  mid=(l+r+1)/2;
		if(check(mid)){
			l=mid;
		}
		else r=mid-1;
	}
	cout<<l;
	return 0;
} 
