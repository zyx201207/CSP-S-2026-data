#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool sameside(char x,char y){
	if((x=='A' || x=='B' || x=='C')&&(y=='A' || y=='B' || y=='C')) return true;
	if((x=='D' || x=='F')&&(y=='D' || y=='F')) return true;
	return false;
}
bool beside(char x, char y){
	ll t=abs(x-y);
	if(t==1) return true;
	if(t==2 &&(x=='D' || x=='F') && (x=='F' || x=='D')) return true;
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		if(s1[0]==s2[0] && s1[1]==s2[1]){
			if(sameside(s1[2],s2[2])){
				if(beside(s1[2],s2[2])){
					cout<<"1111";
				}
				else cout<<"1110";
			}
			else cout<<"1100";
		}
		else cout<<"1000";
	}
	else cout<<"0000";
	return 0;
}
