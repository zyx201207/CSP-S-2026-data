#include<bits/stdc++.h>
using namespace std;
string n1,m1,n2,m2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n1>>m1>>n2>>m2;
	if(n1==n2){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(m1[0]==m2[0]&&m1[1]==m2[1]){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if((m1[2]=='A'&&m2[2]=='B')||(m1[2]=='A'&&m2[2]=='C')||(m1[2]=='B'&&m2[2]=='A')||(m1[2]=='B'&&m2[2]=='C')||(m1[2]=='C'&&m2[2]=='A')||(m1[2]=='C'&&m2[2]=='B')||(m1[2]=='D'&&m2[2]=='F')||(m1[2]=='F'&&m2[2]=='D')){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if((m1[2]=='A'&&m2[2]=='B')||(m1[2]=='B'&&m2[2]=='A')||(m1[2]=='B'&&m2[2]=='C')||(m1[2]=='C'&&m2[2]=='B')||(m1[2]=='D'&&m2[2]=='F')||(m1[2]=='F'&&m2[2]=='D')){
		cout<<1;
	}else{
		cout<<"0";
		return 0;
	}
	return 0;
}

