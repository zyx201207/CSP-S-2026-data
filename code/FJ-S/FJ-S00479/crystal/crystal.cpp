#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ma=0;
long long check(long long x){
	long long l=0,mm=m;
	for(long long i=n;i>=1;i--){
		if(x>a[i]){
			if(mm-(x-a[i])>0){
				l++;
				mm-=(x-a[i]-1);
			}else return l;
		}
	}
	return l;
}
int main(){
	freopen("crystal.in","w",stdin);
	freopen("crystal.out","r",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long l=a[1],r=a[n],mid;
	while(l<=r){
		mid=(l+r)/2;
		if(check(mid)>ma){
			ma=check(mid);
			l=mid+1;
		}else r=mid-1;
	}
	cout<<ma+1;
	return 0;
}
