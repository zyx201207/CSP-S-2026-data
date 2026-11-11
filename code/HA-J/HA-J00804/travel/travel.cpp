#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string q1,q2,w1,w2;
	cin>>q1>>q2>>w1>>w2;
	if(q1[0]==w1[0]&&w1[1]==q1[1])cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
	if(q2[0]==w2[0]&&w2[1]==q2[1])cout<<"1";
	else{
		cout<<"000";
		return 0;
	}
	if(q2[2]=='A'&&w2[2]=='B')cout<<1;
	else if(q2[2]=='A'&&w2[2]=='B')cout<<"1";
	else if(q2[2]=='B'&&w2[2]=='A')cout<<"1";
	else if(q2[2]=='D'&&w2[2]=='F')cout<<"1";
	else if(q2[2]=='F'&&w2[2]=='D')cout<<"1";
	else if(q2[2]=='B'&&w2[2]=='C')cout<<"1";
	else if(q2[2]=='C'&&w2[2]=='B')cout<<"1";
	else if(q2[2]=='A'&&w2[2]=='C')cout<<"1";
	else if(q2[2]=='C'&&w2[2]=='A')cout<<"1";
	else{
		cout<<"00";
		return 0;
	}
	int e=q2[2]-w2[2];
	if(e==1||e==-1)cout<<"1";
	else cout<<"0";
	return 0;
}
