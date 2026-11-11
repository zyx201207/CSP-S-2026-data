#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int a,b,c,d;
	char m,n;
	a=(c1[0]-48)*10+c1[1]-48;
	c=(c2[0]-48)*10+c2[1]-48;
	b=(s1[0]-48)*10+s1[1]-48;
	d=(s2[0]-48)*10+s2[1]-48;
	m=s1[2];
	n=s2[2];
	if(a==c){
		cout<<"1";
		if(b==d){
			cout<<"1";
			if(m=='F'&&n=='D'||m=='D'&&n=='F'){
				cout<<"11";
			}
			else if(m=='A'&&n=='B'||m=='B'&&n=='C'||m=='B'&&n=='A'||m=='C'&&n=='B'){
				cout<<"11";
			}
			else if(m=='A'&&n=='C'||m=='C'&&n=='A'){
				cout<<"10";
			}
			else{cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
}
