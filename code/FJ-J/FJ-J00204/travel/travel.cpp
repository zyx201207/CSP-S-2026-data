//中华人民共和国万岁，世界人民大团结万岁！ 
#include<bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;
bool tyc(char a,char b){
	if(a=='B'&&b=='A') return true;
	if(a=='A'&&b=='B') return true;
	if(a=='C'&&b=='A') return true;
	if(a=='A'&&b=='C') return true;
	if(a=='B'&&b=='C') return true;
	if(a=='C'&&b=='B') return true;
	if(a=='D'&&b=='D') return true;
	if(a=='F'&&b=='F') return true;
	return false;
}
bool xl(char a,char b){
	if(a=='B'&&b=='A') return true;
	if(a=='A'&&b=='B') return true;
	if(a=='B'&&b=='C') return true;
	if(a=='C'&&b=='B') return true;
	if(a=='D'&&b=='D') return true;
	if(a=='F'&&b=='F') return true;
	return false;	
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<"1";
			if(tyc(s1[2],s2[2])){
				cout<<"1";
				if(xl(s1[2],s2[2])){
					cout<<"1";
				}
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";	
	}
	else cout<<"0000";
	
	return 0;
} 

