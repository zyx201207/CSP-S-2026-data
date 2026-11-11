#include<bits/stdc++.h>
using namespace std;
int a1;
string a2;
int b1;
string b2;
int main(){
    freeopen("travel.in","r",stdin);
    freeopen("travel.out","w",stdout);
    int k1,k2;
    cin>>a1>>a2>>b1>>b2;
    if(a1==b1){
    	cout<<"1";
    	if(a2[0]==b2[0]&&a2[1]==b2[1]){
    		cout<<"1";
    		if(a2[2]<='c'){
    			k1=1;
			}
			else{
				k1=2;
			}
			if(b2[2]<='c'){
				k2=1;
			}
			else{
				k2=2;
			}
			if(k1==k2){
				cout<<"1";
				if(a2[2]==b2[2]-1||a2[2]==b2[2]+1){
					cout<<"1";
				}
				else{
					cout<<"0"; 
				}
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
}
