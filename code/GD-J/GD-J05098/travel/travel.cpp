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
		if(s1[0]+s1[1]!=s2[0]+s2[1]){
			cout<<"000";
			return 0;
		}else{
			cout<<"1"; 
			if(!(('A'<=s1[2]&&s1[2]<='C'&&'A'<=s2[2]&&s2[2]<='C')||('D'<=s1[2]&&s1[2]<='F'&&'D'<=s2[2]&&s2[2]<='F'))){
				cout<<"00";
			}else{
				cout<<"1";
				char a,b;
				a=s1[2];
				b=s2[2];
				if((a=='A'&&b=='B')||(a=='B'&&b=='C')||(a=='D'&&b=='F')||(a=='F'&&b=='D')||(a=='C'&&b=='B')||(a=='B'&&b=='A')){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}
		}
	}
	 
	return 0;
} 
