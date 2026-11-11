#include<bits/stdc++.h>
#define int long long
using namespace std;
string c1,s1,c2,s2;
bool chk(char a,char b){
	if(a=='D'&&b=='F'){
		return true;
	}else if(a=='A'||a=='B'||a=='C'){
		if(b=='A'||b=='B'||b=='C'){
			return true;
		}
	}return false;
}bool chk2(char a,char b){
	return a+1==b&&a!='C'&&b!='D';
}signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			if(chk(s1[2],s2[2])||chk(s2[2],s1[2])){
				cout<<1;
				if(chk2(s1[2],s2[2])||chk2(s2[2],s1[2])){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
}
