#include<bits/stdc++.h>
using namespace std; 
int main (){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
   int n;cin>>n;
   long long a[n+5];
   char b[n+5];
   long long df=0;
   long long ans=0;
   for(int i=1;i<=n;i++){
   	 cin>>a[i]>>b[i];
   	 df=(df+a[i])%2;
   }
   for(int i=1;i<=n;){ 
   	 	if(b[i]==b[n]){
		if(a[i]>a[n]){
   	 	   a[i]-=a[n];	
			a[n]=0;
   	 		n--;
   	 	}else if(a[i]<a[n]){
   	 	   a[n]-=a[i];
   	 	   a[i]=0;
   	 	   i++;
   	   }else if(a[i]==a[n]){
   	   	    a[n]=0;
   	   	    a[i]=0;
   	   	    i++;n--;
   	   }
		 }
   	 	else{
   	 		if(a[i]>a[n]){
   	 		a[i]-=a[n];
   	 		ans+=a[n];
   	        a[n]=0;		
		    n--;
   	 	}else if(a[i]<a[n]){
   	 		a[n]-=a[i];
   	 		ans+=a[i];
   	 		a[i]=0;
   	 		i++;	
   	 	}else if(a[i]==a[n]){
   	 		ans+=a[n];
   	 		a[i]=0;
   	 		a[n]=0;
   	 		i++;n--;
   	 	}
	 }
   }	
   cout<<ans;
    return 0;}
