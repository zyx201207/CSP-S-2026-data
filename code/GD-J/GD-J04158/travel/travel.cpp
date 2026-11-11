#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
string c1,c2,a1,a2;
inline bool side(string s){
	if(s[2]=='A'||s[2]=='B'||s[2]=='C')return 1;
	else return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c1>>a1>>c2>>a2;
	if(c1==c2){
		cout<<'1';
		if(a1[0]==a2[0]&&a1[1]==a2[1]){
			cout<<'1';
			if(side(a1)==side(a2)){
				cout<<'1';
				if(a1[2]=='A'&&a2[2]=='B')cout<<'1';
				else if(a1[2]=='B'&&(a2[2]=='A'||a2[2]=='C'))cout<<'1';
				else if(a1[2]=='C'&&a2[2]=='B')cout<<'1';
				else if(a1[2]=='D'&&a2[2]=='E')cout<<'1';
				else if(a1[2]=='E'&&a2[2]=='D')cout<<'1';
				else cout<<'0';
			}else{
				cout<<"00\n";
			}
		}else{
			cout<<"000\n";
		}
	}else{
		cout<<"0000\n";
	}
	return 0;
} 
