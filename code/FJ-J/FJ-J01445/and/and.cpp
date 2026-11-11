#include<bits/stdc++.h>
using namespace std;
long long n,m,s;
long long a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
          if(m==n){
                  s=a[1]   ;    	
          	for(int i=2;i<=n;i++){
          		   s=s&a[i];         		
			  }
			  cout<<s;
			  return 0;
		  }
		  if(m==1){
		  	for(int i=1;i<=n;i++){
		  		 s=max(s,a[i]);
			  }
			  cout<<s;
			  return 0;
		  }
		  if(m==2){
		  	for(int i=1;i<n;i++){
		  		for(int j=i+1;j<=n;j++){	
	  			 s=max(s,a[i]&a[j]) ;
				  }
			  }
			  cout<<s;
			  return 0;
		  }
        if(m==3){
        		for(int i=1;i<n-1;i++){
		  		for(int j=i+1;j<n;j++){
				  for(int k=j;k<=n;k++){				  
	  			 s=max(s,a[i]&a[j]&a[k]);
				  }
			  }
		}
			  cout<<s;
			  return 0;
		}
		        if(m==4){
        		for(int i=1;i<n-2;i++){
		  		for(int j=i+1;j<n-1;j++){
				  for(int k=j;k<n;k++){	
				  for(int l=k;l<=n;l++){
				  		  
	  			 s=max(s,a[i]&a[j]&a[k]&a[l]);}
				  }
			  }
		}
			  cout<<s;
			  return 0;
		}
				        if(m==5){
        		for(int i=1;i<n-3;i++){
		  		for(int j=i+1;j<n-2;j++){
				  for(int k=j;k<n-1;k++){	
				  for(int l=k;l<n;l++){
				  		  for(int q=l;q<=n;q++){
							
	  			 s=max(s,a[i]&a[j]&a[k]&a[l]&a[q]);
				   }
				   }
				  }
			  }
		}
			  cout<<s;
			  return 0;
		}
		
						        if(m==6){
        		for(int i=1;i<n-4;i++){
		  		for(int j=i+1;j<n-3;j++){
				  for(int k=j;k<n-2;k++){	
				  for(int l=k;l<n-1;l++){
				  		  for(int q=l;q<n;q++){
							for(int o=q;o<=n;o++){
							
	  			 s=max(s,a[i]&a[j]&a[k]&a[l]&a[q]&a[o]);
				   }
				   }
				   }
				  }
			  }
		}
			  cout<<s;
			  return 0;
		}
	sort(a+1,a+n+1);
	s=a[n];
	for(int i=n-1;i>=n-m+1;i++){
		s=s&a[i];
	}
	cout<<s;	
	return 0;
} 
