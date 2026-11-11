#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string c1,s1,c2,s2;cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0; 
	}
	else{
		cout<<"1";
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<"1";
			int wei1=s1[2]-'A'+1,wei2=s2[2]-'A'+1;
			if(wei1>=4&&wei2>=4){
				cout<<"11";
				return 0;
			}
			if(wei1<=3&&wei2<=3){
				cout<<"1";
				if(abs(wei1-wei2)==1){
					cout<<"1";
					return 0; 
				}
				else{
					cout<<"0";
					return 0;
				}
			}
			cout<<"00";
			return 0; 
		}
		else{
			cout<<"000";
			return 0; 
		}
	}
	return 0;
} 
