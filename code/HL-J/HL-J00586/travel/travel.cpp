#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}

	if(s1[0]==s2[0] && s1[1]==s2[1]){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0; 
	}

	for(int i=0;i<3;i++){
		if(i==2){
			if(s1[i]=='A' && s2[i]=='B' || s1[i]=='B' && s2[i]=='A' || s1[i]=='B' && s2[i]=='C' || s1[i]=='C' && s2[i]=='B' || s1[i]=='A' && s2[2]=='C' || s1[2]=='C' && s2[2]=='A'){
				cout<<1; 
			}
			else if(s1[i]=='D' && s2[i]=='F' || s1[i]=='F' && s2[i]=='D'){
		        cout<<"11";
	 	        return 0;
	        }
	        else{
		        cout<<"00";
				return 0;
	        }
	        
	        if(s1[i]=='A' && s2[i]=='B' || s1[i]=='B' && s2[i]=='A' || s1[i]=='B' && s2[i]=='C' || s1[i]=='C' && s2[i]=='B'){
	        	cout<<1;
			}
			else{
				cout<<0;
				return 0;
			}
		}
	}
	return 0;
} 
