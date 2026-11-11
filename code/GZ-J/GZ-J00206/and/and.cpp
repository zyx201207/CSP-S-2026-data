//GZ-J00206 杨俊毅 遵义市南白初级中学 
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans=-1;
int main(){
  freopen("and.in","r",stdin);
  freopen("and.out","w",stdout);
  cin>>n>>m;
  for(long long i=1;i<=n;i++){
  	cin>>a[i];
  }
  if(n==m){
  	ans=a[1];
  	for(long long i=1;i<=n;i++){
  		ans=ans&a[i];
	  }
	  cout<<ans;
	  return 0;
  }else if(m==1){
  	for(long long i=1;i<=n;i++){
  		ans=max(ans,a[i]);
	  }
	  cout<<ans;
	  return 0;
  }else if(m==2){
  	 for(long long i=1;i<=n;i++){
  	 	for(long long j=1;j<=n;j++){
  	 		    if(i!=j){
  	 		    	long long temp=a[i]&a[j];
  	 		    	ans=max(ans,temp);
				   }
		   }
	   }
	   cout<<ans;
  }else{
  	sort(a+1,a+1+n);
  	ans=a[n];
  	for(long long i=n;i>=m;i--){
  		ans=ans&a[i];
	  }
	  cout<<ans;
  }
	return 0;
}

