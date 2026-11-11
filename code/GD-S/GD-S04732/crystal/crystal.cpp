#include<bits/stdc++.h>
using namespace std;

const int N=5e5+5;
long long n,m,a[N];
bool check(long long k){
	long long b=a[k-1]*k,c=0;
	for(long long i=0;i<k;i++)c+=a[i];
	return b-c<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	long long l=1,r=n;
	while(l<r){
		long long mid=l+(r-l)/2;
		if(check(mid)){
			l=mid+1;
		}else{
			r=mid;
		}
	}
	cout<<r-1;
	
	return 0;
} 
