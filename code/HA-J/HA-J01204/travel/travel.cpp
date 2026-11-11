#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","r",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a==c){
    	if(b[1]==d[1]&&b[0]==b[0]){
    	        if(b[2]<='C'&&d[2]<='C'){
    	        	if(b[2]-d[2]==1||d[2]-b[2]==1){
    	        		cout<<"1111";
    	        	}
    	         else{cout<<"1110";}
    	            }
    	         else if(b[2]>='D'&&d[2]>='D'){
    	            if(b[2]-d[2]==1||d[2]-b[2]==1){
    	        		cout<<"1111";
    	        	} else{cout<<"1110";}     	
    	            } else{cout<<"1100";}
    			} else{cout<<"1000";}
  }
  else{cout<<"0000";}
  return 0;
}


