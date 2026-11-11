#include<bits/stdc++.h>
using namespace std;
int main(){
	  freopen("travel.in","r",stdin);
      freopen("travel.out","w",stdout);
      string c1,s1,c2,s2;
      cin>>c1>>s1>>c2>>s2;
      bool a=false;
	  if(c1==c2)
      {
      	     cout<<"1";
	         for(int i=0;i<=1;i++){
	    	     if(s1[i]==s2[i])
		      {   
		      	  a=true;
			  }
		     else{
		     	 a=false;
			 }
		}
	     if(a)
	     {
	     	 cout<<"1";
	     	 char b=s1[2];
	     	 char c=s2[2];
	     	 if(b>='A'&&b<='C'&&c>='A'&&c<='C'){
	     	 	   cout<<"1";
			  }
		      else{
				  
			  if (b>='E'&&b<='F'&&c>='E'&&c<='F'){
	     	 	   cout<<"1";
			  }
		       else {
		       	 cout<<"0";
			   }
		  }
		 }
	     else{
	     	 cout<<"0"<<"0";
		 }
	  char e=s1[2];
	  char f=s2[2];
	  if(e>f&&a)
	  {
	  	   if(e-f!=1)
	  	   {
	  	   	    cout<<"0";
			 }
		   else{
		   	    if(e=='D'&&f=='C')
		   	     {
		   	     	  cout<<"0";
					}
		       if(e>='A'&&e<='C'&&f>='A'&&f<='C'){
	     	 	   cout<<"1";
			  }
		  if (e>='E'&&e<='F'&&f>='E'&&f<='F'){
	     	 	   cout<<"1";
			  }
		  }    
		        
		   }
	  if(e<f&&a)
	  	    if(f-e!=1)
	  	   {
	  	   	    cout<<"0";
			 }
		   else{
		   	    if(e=='C'&&f=='D')
		   	     {
		   	     	  cout<<"0";
					}
		       if(e>='A'&&e<='C'&&f>='A'&&f<='C'){
	     	 	   cout<<"1";
			  }
		  if (e>='E'&&e<='F'&&f>='E'&&f<='F'){
	     	 	   cout<<"1";
			  }
		  }    
        }
        else{
	  	 cout<<"0"<<"0"<<"0"<<"0";
	  }
	  fclose(stdin);
      fclose(stdout);
	  return 0;
}
