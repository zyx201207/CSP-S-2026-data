#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}else{
		cout<<"1";
		int sz1=s1[0]-'0'+s1[1]-'0';
		int sz2=s2[0]-'0'+s2[1]-'0';
		if(sz1!=sz2){
			cout<<"000";
			return 0;
		}else{
			cout<<"1";
			if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')){
				cout<<"1";
				if(abs(s1[2]-s2[2])==1){
					cout<<"1";
					return 0;
				}else{
					cout<<"0";
					return 0;
				}
			}else if((s1[2]=='D'||s1[2]=='F')&&(s1[2]=='D'||s1[2]=='F')){
				cout<<"11";
				return 0;
			}else{
				cout<<"00";
			}
		}
	}
	
	return 0;
}
