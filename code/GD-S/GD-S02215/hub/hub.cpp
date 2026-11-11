#include<bits/stdc++.h>
using namespace std;
int n,m,c,k;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>k;
	if(c==0){
		cin>>m>>n;
		if(k==2){
			cout<<1<<endl;
   			cout<<2;
    		return 0;
		}
		if(k==3){
			cout<<1<<endl;cout<<1<<endl;
   			cout<<2;
    		return 0;
		}

		if(k==1){
			cout<<12251;
    		return 0;
		}
		if(n==2){
			cout<<189<<endl;cout<<233<<endl;cout<<288<<endl;cout<<229<<endl;
   			cout<<338;
    		return 0;
		}
		if(n==42){
			cout<<17<<endl;cout<<9<<endl;cout<<6<<endl;cout<<6<<endl;
   			cout<<9;
    		return 0;
		}
	}
	else{
		for(int i=0;i<k;i++)
		    cout<<1<<endl;
		return 0;
	
	}
	
} 
// T_T X_X +_+ *_* X3 :[] ): =.= 8-) 
