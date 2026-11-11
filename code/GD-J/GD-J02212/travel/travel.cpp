#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travle.in","r",stdin);
	freopen("travle.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]==c2[0]&&c1[1]==c2[1]){
		cout<<'1';
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<'1';
			if((s1[2]<=67&&s1[2]>=65)&&(s2[2]<=67&&s2[2]>=65)){
				cout<<'1';
				if(abs(int(s1[2])-int(s2[2]))==1)cout<<'1';
				else cout<<'0';
			}
			else if((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F')){
				cout<<"11";
			}
			else cout<<"00";	
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
} 
