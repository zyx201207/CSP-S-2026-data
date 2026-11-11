#include<bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;

bool sd[10][10];

void init(){
	sd[0][1]=true;sd[1][0]=true;
	sd[0][2]=true;sd[2][0]=true;
	sd[1][2]=true;sd[2][1]=true;
	sd[3][4]=true;sd[4][3]=true;
	return;
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	init();
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	int a=(s1[0]-'0')*10+s1[1]-'0';
	int b=(s2[0]-'0')*10+s2[1]-'0';
	if(a!=b){
			cout<<"000";
			return 0;
	}
	cout<<"1";
	if(!sd[s1[2]-'A'][s2[2]-'A']){
		cout<<"00";
		return 0;
	}
	cout<<"1";
	if(abs(s1[2]-'A'-(s2[2]-'A'))!=1){
		cout<<"0";
		return 0;
	}
	cout<<"1";
	return 0;
}
