#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string csr,zwr,csx,zwx;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    cin>>csr>>zwr>>csx>>zwx;
    if(csr==csx){
    	if(zwr[0]==zwx[0]&&zwr[1]==zwx[1]){
    			if(zwr[2]>='A'&&zwr[2]<='C'&&zwx[2]>='A'&&zwx[2]<='C'){
    				if(abs(zwr[2]-zwx[2])==1){
    					cout<<"1111";
    					return 0;
					}
					else{
						cout<<"1110";
						return 0;
					}
				}
				else if((zwr[2]=='D'&&zwx[2]=='F')||(zwr[2]=='F'&&zwx[2]=='D')){
					cout<<"1111";
					return 0;
				}
			    else{
			    	cout<<"1100";
			    	return 0;
				}
		}
		else{
			cout<<"1000";
			return 0;
		}
	}
	else{
		cout<<"0000";
		return 0;
	}
	return 0;
}
