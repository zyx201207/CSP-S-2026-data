#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int a,b,f;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	a=(s1[0]-'0')*10+s1[1]-'0';
	b=(s2[0]-'0')*10+s2[1]-'0';
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	else{
		if(a!=b){
			cout<<"1000";
			return 0;
		}
		else{
			char x,y;
			x=s1[2],y=s2[2];
			if((x=='A' && y=='B') || (x=='B' && y=='A') || (x=='A' && y=='C') || (x=='C' && y=='A') || (x=='D' && y=='F') || (x=='F' && y=='D') || (x=='B' && y=='C') || (x=='C' && y=='B')){
			}
			else{
				cout<<"1100";
				return 0;
			}
			if((x=='A' && y=='B') || (x=='B' && y=='A') || (x=='D' && y=='F') || (x=='F' && y=='D') || (x=='B' && y=='C') || (x=='C' && y=='B')){
				cout<<"1111";
			}
			else{
				cout<<"1110";
			}
		}
	}
	return 0;
}
