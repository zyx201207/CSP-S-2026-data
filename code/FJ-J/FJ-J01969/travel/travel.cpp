#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>c2>>s1>>s2;
	int a=(c1[0]-'0')*10+c1[1]-'0';
	int b=(s1[0]-'0')*10+s1[1]-'0';
	if(a==b) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	int c=(c2[0]-'0')*10+c2[1]-'0';
	int d=(s2[0]-'0')*10+s2[1]-'0';
	if(c==d) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	char e=c2[2];
	char f=s2[2];
	if(e=='D'&&f=='F'){
		cout<<"11";
		return 0;
	}
	if(f=='D'&&e=='F'){
		cout<<"11";
		return 0;
	}
	if(e=='A'){
		if(f=='B'){
		cout<<"11";
		return 0;
		}
		if(f=='C'){
		cout<<"10";
		return 0;
		}
	}
	if(e=='B'){
		if(f=='A'||f=='C'){
		cout<<"11";
		return 0;
		}
	}
	if(e=='C'){
		if(f=='B'){
		cout<<"11";
		return 0;
		}
		if(f=='A'){
		cout<<"10";
		return 0;
		}
	}
	cout<<"00";
	return 0;
}
