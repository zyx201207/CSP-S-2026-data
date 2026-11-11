#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
long long check(long long x){
	long long q=0,cnt=0;
	while(a[q]<=x){
		cnt+=x-a[q];
		q++;
	}
	return cnt;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	long long l=a[0],r=a[n-1],mid=0;
	while(l<r){
		mid=(l+r+1)/2;
		long long tmp=check(mid);
		if(tmp<m){
			l=mid;
		}
		else if(tmp>m){
			r=mid-1;
		}
		else{
			break;
		}
	}
	long long ans=0;
	while(a[ans]<=mid){
		ans++;
	}
	cout<<ans;
	return 0;
}
