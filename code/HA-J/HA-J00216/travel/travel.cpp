#include<bits/stdc++.h>
using namespace std;
int n,a;
string m,b;
bool check(char x,char y){
	if((x=='A'&&y=='B')||(x=='B'&&y=='A')) return 1;
	if((x=='B'&&y<='C')||(x=='C'&&y<='B')) return 1;
	if((x=='C'&&y=='B')||(x=='B'&&y=='C')) return 1;
	if((x=='D'&&y=='F')||(x=='F'&&y=='D')) return 1;
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m>>a>>b;
	if(n!=a){
		cout<<"0000";
		return 0;
	}
	if(m[0]==b[0]&&m[1]==b[1]){
		if((b[2]>'C'&&m[2]>'C')||(b[2]<'D'&&m[2]<'D')){
			if(check(b[2],m[2])){
				cout<<"1111";
				return 0;
			}
			else{
			cout<<"1110";return 0;
			}
			
		}	
		else{
			cout<<"1100";
			return 0;
		}
	}
	else{
		cout<<"1000";
		return 0;
	}
	return 0;
}
