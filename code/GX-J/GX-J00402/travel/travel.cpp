#include<iostream>
#include<string>
using namespace std;
bool a=0,b=0,c=0,d=0;
int main(){
	cin.tie(0);
	string s1,s2,s3,s4;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> s1 >> s2 >> s3 >> s4;
	if(s1==s3){
		a=1;
		if(s2[0]==s4[0]&&s2[1]==s4[1]){
			b=1;
			if(s2[2]=='F'&&s4[2]=='D'||s4[2]=='F'&&s2[2]=='D'||s2[2]=='A'&&s4[2]=='B'||s2[2]=='B'&&s4[2]=='A'||s2[2]=='C'&&s4[2]=='B'||s2[2]=='B'&&s4[2]=='C'){
				c=1,d=1;
			}else if(s2[2]=='C'&&s4[2]=='D'||s2[2]=='D'&&s4[2]=='C')c=0;
			else c=1;
		}
	}
	cout << a << b << c << d;
	return 0;
}
