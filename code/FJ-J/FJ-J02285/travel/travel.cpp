#include<bits/stdc++.h> 
using namespace std;
string s1,s2;
string c1,c2;
bool pd(char a,char b){
	if(a=='A'||a=='B'||a=='C'){
		if(b=='A'||b=='B'||b=='C'){
			cout<<1;
			if((a=='A'||a=='B')&&(b=='A'||b=='B'))cout<<1;
			else if((a=='C'||a=='B')&&(b=='C'||b=='B'))cout<<1;
			else cout<<0;
		}else{
			cout<<"00";
		}
	}else{
		if(b=='D'||b=='F'){
			cout<<"11";
		}else{
			cout<<"00";
		}
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2;
	cin>>c1>>c2;
	if(s1==c1){
		cout<<1;
		if(s2[0]==c2[0]&&s2[1]==c2[1]){
			cout<<1;
			pd(s2[2],c2[2]);
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
