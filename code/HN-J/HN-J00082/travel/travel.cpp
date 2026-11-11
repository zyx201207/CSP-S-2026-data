
#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","W",stdout);
    string Rx,Rz,Xx,Xz;
    cin>>Rx>>Rz>>Xx>>Xz;
    if(Rx==Xx){
        cout<<"1";
    }
        else{
			cout<<"0";
		}
//1
    if(Rx==Xx){
    	if(Rz[0]==Xz[0]){
    		if(Rz[1]==Xz[1]){
            	cout<<"1";//2
            	    if((Xz[2]=='F' and Rz[2]=='D')or(Xz[2]=='D' and Rz[2]=='F')or(Xz[2]=='A' and(Rz[2]=='C' or Rz[2]=='B'))or(Xz[2]=='C' and(Rz[2]=='A' or Rz[2]=='B'))or(Xz[2]=='B' and(Rz[2]=='C' or Rz[2]=='A'))){
            			cout<<"1";//3
					}
			else{cout<<"0";}
			           	
				
				if((Xz[2]=='F' and Rz[2]=='D')or(Xz[2]=='D' and Rz[2]=='F')or(Xz[2]=='A' and Rz[2]=='B')or(Xz[2]=='B' and Rz[2]=='A')or(Xz[2]=='B' and Rz[2]=='C')or(Xz[2]=='C' and Rz[2]=='B')){
					cout<<"1";
				}
            	else{cout<<"0";}
            	
        	}
        	
        	else{cout<<"0";}
        
    	}
    	
        else{cout<<"0";}
        
	}
	
	else{cout<<"0";}


    fclose(stdin);
    fclose(stdout);
    return 0;
}
