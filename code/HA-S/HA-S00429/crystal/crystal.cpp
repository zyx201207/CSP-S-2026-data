#include<bits/stdc++.h>
using namespace std;
long long a[500005],sum[500005];
long long ans=1; 
long long n,m;
bool check(long long x){
	bool flag=0;
	for(long long i=x;i<=n;i++){
		if(sum[i]-sum[i-x]+m>=x*a[i]){
			ans=max(ans,x);
			flag=1;
		}
	}
	return flag;
}
int main(){
	freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=a[i];
		sum[i]+=sum[i-1];
	}
 	long long r=1,l=n;
   	while(r<=l){
	   	long long mid=(l+r)/2;
	   	if(check(mid)){
	   		r=mid+1;
	  	}
	    else{
	    	l=mid-1;
	    }
    }
	cout<<ans;
}
