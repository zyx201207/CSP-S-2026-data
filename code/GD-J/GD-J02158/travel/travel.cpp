#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){cout<<"0000";return 0;}
	int lR=(s1[0]-'0')+(s1[1]-'0'),sR=(s1[2]-'A'),lX=(s2[0]-'0')+(s2[1]-'0'),sX=(s2[2]-'A');
	if(lR!=lX){cout<<"1000";return 0;}
	if(!(sR<=2&&sX<=2||sR>=3&&sX>=3)){cout<<"1100";return 0;}
	if(!(abs(sR-sX)<=1)){cout<<"1110";return 0;}
	cout<<"1111";
	return 0;
}
