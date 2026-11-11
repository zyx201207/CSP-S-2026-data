#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s1,c1,s2,c2;
ll a,b,c,d;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]==c2[0]&&c1[1]==c2[1]) {
		a=1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			b=1;
			if(s1[2]=='A'&&s2[2]=='B'||s1[2]=='A'&&s2[2]=='C'||s1[2]=='B'&&s2[2]=='C'||s1[2]=='B'&&s2[2]=='A'||s1[2]=='C'&&s2[2]=='A'||s1[2]=='C'&&s2[2]=='B'||s1[2]=='D'&&s2[2]=='F'||s1[2]=='F'&&s2[2]=='D') {
				c=1;
				if(s1[2]=='A'&&s2[2]=='B'||s1[2]=='B'&&s2[2]=='C'||s1[2]=='D'&&s2[2]=='F'||s2[2]=='A'&&s1[2]=='B'||s2[2]=='B'&&s1[2]=='C'||s2[2]=='D'&&s1[2]=='F') d=1;
			}
		}
	}
	cout<<a<<b<<c<<d;
	
	return 0;
}
