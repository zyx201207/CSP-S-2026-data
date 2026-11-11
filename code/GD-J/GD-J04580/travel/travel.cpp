#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
	}
	else{
		cout<<"0000";
		return 0;
	}
	for(int i=0;i<2;i++){
		if(s1[i]!=s2[i]){
			cout<<"000";
			return 0;
		}
	}
	cout<<"1";
	if(s1[2]<=67&&s2[2]<=67){
		cout<<"1";
	}
	else if(s1[2]>67&&s2[2]>67){
		cout<<"11";
		return 0;
	}
	else{
		cout<<"00";
		return 0; 
	}
	if(s1[2]=='B'||s2[2]=='B'){//¿ÉÄÜ±¨´í 
		cout<<"1";
	}
	else{
		cout<<"0"; 
	}
	return 0;
}
