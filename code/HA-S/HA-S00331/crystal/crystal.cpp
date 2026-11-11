#include<bits/stdc++.h>
using namespace std;
long long n,m;
const long long N=5e5+10;
long long a[N];
long long check(int x){
	long long s=0;
	long long q=m;
	long long tot=1;
	while(q>0&&x-tot>=0){
		if(q-(a[x]-a[x-tot])>=0){
			q=q-(a[x]-a[x-tot]);
			s++;
		}
		tot++;
	}
	return ++s;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	if(n==1){
		cout<<1;
		return 0;
	}
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	long long l=0,r=n-1;
	long long mid=0;
	while(l<r){
		mid=(l+r+1)/2;
		long long p1=check(mid-1);
		long long p2=check(mid);
		if(p1<p2){
			l=mid;
		}
		else{
			r=mid-1;
		}
	}
	cout<<check(l);
	return 0;
}
