#include<bits/stdc++.h>
using namespace std;
int c,n,d,t,x[2000005],ans;
int main(){
  //freopen(".in","r",stdin);
  //freopen(".out","w",stdout);
  cin>>c>>t;
  while(t--){
  	
  	cin>>n>>d;
  	
  	for(int i=1;i<=n;i++){
  	  cin>>x[i];long long l=1,r=i;
  	  while (l>=r){
  	  	long long mid=(l+r)/2;
  	  	if(x[i]-x[mid]==2*d-1){
  	  		if(x[mid]!=x[mid-1]&&x[mid]!=x[mid+1]&&x[i-1]!=x[i]){
  	  			ans++;
  	  			
  	  		}
  	  	}else if(x[mid]>x[i]-2*d+1){
  	  		r--;
  	  	}
  	  	else l++;
  	  }
  	  
  	}
  	cout<<ans<<'\n';
  	
  } 
  return 0;
}


