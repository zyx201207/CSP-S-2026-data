#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a_2,b_2;
	int a_1,b_1;
	cin>>a_1>>a_2>>b_1>>b_2;
	if(!(a_1==b_1)){
		cout<<"0000";
		return 0;
	}
	cout<<1;
	if(!(a_2[0]==b_2[0] && a_2[1]==b_2[1])){
		cout<<"000";
		return 0;
	}
	cout<<1;
	bool b=0,c=0;
	if(a_2[2]=='A' && b_2[2]=='B')b=1;
	if(a_2[2]=='A' && b_2[2]=='C')b=1;
	if(a_2[2]=='B' && b_2[2]=='A')b=1;
	if(a_2[2]=='B' && b_2[2]=='C')b=1;
	if(a_2[2]=='C' && b_2[2]=='B')b=1;
	if(a_2[2]=='C' && b_2[2]=='A'){b=1;c=1;}
	if(a_2[2]=='D' && b_2[2]=='F')b=1;
	if(a_2[2]=='F' && b_2[2]=='D')b=1;
	if(b) cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if(c) cout<<0;
	else cout<<1;
	return 0;
}
