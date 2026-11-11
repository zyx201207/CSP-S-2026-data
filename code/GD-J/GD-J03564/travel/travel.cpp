#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a1,a2,b1,b2;
	char a3,b3;
    if(a1==b1){
    	cout<<"1";
    	if(a2==b2){
    		cout<<"1";
    		 if(((a3=='A' || a3=='B' || a3=='C')&&(b3=='A' || b3=='B' || b3=='C'))||((a3=='D' || a3=='E')&&(b3=='D' || b3=='E'))){
    		 	 cout<<"1";
    		 	 if(abs(b3-a3)==1){
    			    cout<<"1";
			     }else{
			    	 cout<<"0";
				 }
			 }else{
			 	cout<<"00";
			 }
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
