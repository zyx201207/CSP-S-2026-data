#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
int check(int num){
	long long sum=0;
	for(int i=1;i<num;i++){
		sum+=a[i];
	}
	long long minnum=1e18+1e12;
	for(int i=num;i<=n;i++){
		sum-=a[i-num];
		sum+=a[i];
		minnum=min(a[i]*num-sum,minnum);
	}

	return minnum<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=1,r=n;
	while(l<r){
		int mid=(l+r+1)>>1;
		if(check(mid)){
			l=mid;
		}else{
			r=mid-1;
		}
	}
	cout<<l;
	return 0;
}
