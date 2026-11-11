#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,c3,c4;
	cin>>c1>>c2>>c3>>c4;
	
    if(c1==c3){
        cout<<"1";
        if(c2==c4+1 || c2==c4-1){
			cout<<"111";
			
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
