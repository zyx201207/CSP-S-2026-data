#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<"1";
	else{
		cout<<"0000"<<endl;
		return 0;
	}
	for(int i=0;i<s1.size()-1;i++){
		if(s1[i]==s2[i]) continue;
		else{
			cout<<"000"<<endl;
			return 0;
		} 
	}
	cout<<"1";
	char x=s1[2],y=s2[2];
	if((x=='A'&&y=='B')||(x=='B'&&y=='C')||(x=='A'&&y=='C')||(x=='D'&&y=='E')||(y=='A'&&x=='B')||(y=='B'&&x=='C')||(y=='D'&&x=='E')||(y=='A'&&x=='C')) cout<<"1";
	else{
		cout<<"00"<<endl;
		return 0;
	}
	if((x=='A'&&y=='B')||(x=='B'&&y=='C')||(x=='D'&&y=='E')||(y=='A'&&x=='B')||(y=='B'&&x=='C')||(y=='D'&&x=='E')) cout<<"1";
	else{
		cout<<"0"<<endl;
		return 0;
	}
	return 0;
} 
