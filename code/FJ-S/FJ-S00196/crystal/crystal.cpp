#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],sum,maxn;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long mid=1;
	while(mid<=n){
		sum=0;
		for(int i=1;i<mid;i++){
			sum+=(a[mid]-a[i]);
		}
		if(sum<=m){
			mid++;
		}else{
			break;
		}
		maxn=mid-1;
	}
	cout<<maxn;
	return 0;
} 
