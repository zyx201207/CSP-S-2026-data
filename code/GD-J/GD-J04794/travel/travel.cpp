#include <bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]==c2[0]&&c1[1]==c2[1]){
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
		    cout<<1;
		    if((s1[2]-s2[2]<=2||s2[2]-s1[2]<=2)&&((s1[2]+s2[2])!=4&&(s1[2]+s2[2])!=5&&(s1[2]+s2[2])!=6)){
		    	cout<<"1";
		    	if(s1[2]-s2[2]==1||s2[2]-s1[2]==1){
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
