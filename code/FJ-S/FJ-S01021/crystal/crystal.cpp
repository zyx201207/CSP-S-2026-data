#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long m,mx=-1e14,mn=1e14;
long long a[N];
int n;
int ef(long long x){
	long long ans=0,sum=0;
	for(int i=1;i<=n;i++){
		if(a[i]<=x){
			ans+=(x-a[i]);
			sum++;
		}
	}
	if(ans<=m){
		return sum;
	}else{
		return -1;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
		mn=min(mn,a[i]);
	}
	long long l=mn,r=mx,sumx=0;
	while(l<=r){
		long long mid=(l+r)/2;
		if(ef(mid)!=-1){
			long long ll=ef(mid);
			sumx=max(sumx,ll);
			l=mid+1;
		}else{
			r=mid-1;
		}
		
	}
	cout<<sumx;
	return 0;
} 
