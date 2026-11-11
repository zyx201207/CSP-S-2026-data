#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    for(int i=0;i<2;i++){
    	if(c1[i]!=c2[i]){
    		cout<<"0000";
    		return 0;
		}
	}
	for(int i=0;i<2;i++){
		if(s1[i]!=s2[i]){
			cout<<"1000";
			return 0;
		}
	}
	if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='D'||s2[2]=='F')){
		cout<<"1100";
		return 0;
	}
	if((s2[2]=='A'||s2[2]=='B'||s2[2]=='C')&&(s1[2]=='D'||s1[2]=='F')){
		cout<<"1100";
		return 0;
	}
	if((s1[2]=='A'&&s2[2]=='c')||(s2[2]=='A'||s1[2]=='c')){
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	return 0;
}
