#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);	
    freopen("travel.out","w",stdout);	
    int c1,c2,s1,s2;
    char s11,s22;
    cin>>c1>>s1>>s11>>c2>>s2>>s22;
    if(c1!=c2){
    	cout<<"0000";
//    	return 0;
	}	
	else{
		if(s1!=s2){
			cout<<"1000";
//			return 0;
		}
		else{
			if((s11=='F'&&s22=='D')||(s11=='D'&&s22=='F')||(s11=='A'&&s22=='B')||(s11=='B'&&s22=='A')||(s11=='B'&&s22=='C')||(s11=='C'&&s22=='B')){
				cout<<"1111";
//				return 0;
			}
			else {
				cout<<"1110";
//				return 0;
			}
		}
	}

	return 0;
} 
