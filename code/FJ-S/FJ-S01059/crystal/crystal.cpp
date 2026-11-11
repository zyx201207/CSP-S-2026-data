#include<bits/stdc++.h>
using namespace std;
const int mxn=5*100000+5;
long long n,m,sum=0,ans=-1;
long long a[mxn];
long long cnt[mxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
       cin>>a[i];
	}
	sort(a,a+n);
	if(n<=16&&m<=1000){
		for(long long i=1;i<n;i++){
		   for(long long j=i-1;j>=0;j--){
		   	  sum+=a[i]-a[j];
		   	  if(sum<=m){
		   	  	ans=max(ans,i-j+1);
			  }
		   }
		   sum=0;
		}
		cout<<ans;
	}
	if(n<=5000&&m<=1000000000&&n>16&&m>1000){
		for(long long i=1;i<n;i++){
		   for(long long j=i-1;j>=0;j--){
		   	  sum+=a[i]-a[j];
		   	  if(sum<=m){
		   	  	ans=max(ans,i-j+1);
			  }
		   }
		   sum=0;
		}
		cout<<ans;
	}
	if(n<=5*100000&&m<=1e8&&n>5000&&m>1e6){
		for(long long i=1;i<n;i++){
		   for(long long j=i-1;j>=0;j--){
		   	  sum+=a[i]-a[j];
		   	  if(sum<=m){
		   	  	ans=max(ans,i-j+1);
			  }
		   }
		   sum=0;
		}
		cout<<ans;
	}
	if(n<=5*100000&&m<1e18&&n>5000&&m>1e8){
		for(long long i=1;i<n;i++){
		   for(long long j=i-1;j>=0;j--){
		   	  sum+=a[i]-a[j];
		   	  if(sum<=m){
		   	  	ans=max(ans,i-j+1);
			  }
		   }
		   sum=0;
		}
		cout<<ans;
	}
	return 0;
}
