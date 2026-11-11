#include<bits/stdc++.h>
using namespace std; 
int main(){
	  freopen("string.in","r",stdin);
      freopen("string.out","w",stdout);
	   int n,u=0,sum=0;
	   cin>>n;
	   int a;
	   string c1;
	   string s;
	   for(int i=1;i<=n;i++){
	   	   cin>>a>>c1;
	   	   for(int j=1;j<=a;j++){
	   	   	     s+=c1;
			  }
	   }
       bool b=false;
       	       for(int j=s.size();j>=1;j--){
	   for(int i=1;i<=s.size();i++){
				    if(s[j]==s[i])
					 {
				     	 b=true;
					 }
				     else{
				     	 b=false;
				     	 break;
					 }
				  }
	   }
      if(b){
      	  cout<<0;
	  }
	 else{
	      cout<<2;
	  }
	  //fclose(stdin);
      //fclose(stdout);
      return 0;
}
