#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005],s[500005];

int main(){
  freopen("crystal.in","r",stdin);
  freopen("crystal.out","w",stdout);
  cin>>n>>m;long long ans=0;
  for(int i=1;i<=n;i++){
  	cin>>a[i];
  	
  }long long cnt; 
  sort(a+1,a+n+1);
  
  for(int i=1;i<=n;i++){
  	s[i]=s[i-1]+a[i-1];
  	cnt=a[i]*(i-1)-s[i];
  	if(cnt>m){
         //cout<<1; 
		long long l=1,r=i;
		 		
  		while(l<=r){//cout<<1;
  			long long mid=(l+r)/2;
  			if(cnt-(mid-1)*s[mid]<=m){
  			    r--;
  				if(cnt-(mid-1)*s[mid]-m==0){
  					r=mid;
  					
  				}	
  			}
  			else {
  		l++	;
  			}
  		
  	  if(i-r+1>ans){
  	  	ans=i-r+1;
  	  	
  	  }	
  	}
	  }
  	else ans=i;
  }cout<<ans;
  return 0;
}


