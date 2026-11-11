#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string c1,c2,s1,s2;
int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>c1>>s1>>c2>>s2;
	//1
	if(c1==c2)cout<<1;
	else {
		cout<<"0000";
		return 0;
	}
	//2
	if(s1[0]==s2[0] && s1[1]==s2[1])cout<<1;
	else cout<<0;
	//3
	if(s1[0]==s2[0] && s1[1]==s2[1] && s1[2]<='C' && s2[2]<='C' or s1[2]>'C' && s2[2]>'C')cout<<1;
	else cout<<0;
	//4
	if(s1[2]=='A' && s2[2]=='B' or s1[2]=='c' && s2[2]=='B' or s1[2]=='F' && s2[2]=='D')
		cout<<1;
	else cout<<0;
	
	return 0;
}
