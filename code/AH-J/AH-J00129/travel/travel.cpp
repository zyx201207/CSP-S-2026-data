#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string c1,s1,c2,s2;
bool cmp(char a,char b){
	char c=ll(a)+1,d=a-1;
	if((a=='D'&&b=='F')||(a=='F'&&b=='D')) return 1;
	else if(c==b||d==b) return 1;
	else return 0;
}
bool cmp2(char a,char b){
	if(a=='A'){
		if(b=='B'||b=='C') return 1;
		else return 0;
	}else if(a=='B'){
		if(b=='A'||b=='C') return 1;
		else return 0;
	}else if(a=='C'){
		if(b=='A'||b=='B') return 1;
		else return 0;
	}else if(a=='D'){
		if(b=='F') return 1;
		else return 0;
	}else{
		if(b=='D') return 1;
		else return 0;
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<1;
	else cout<<0;
	string s3=s1.substr(0,2),s4=s2.substr(0,2);
	if(s3==s4&&c1==c2) cout<<1;
	else cout<<0;
	char s5=s1[2]; char s6=s2[2];
	if(c1==c2&&s3==s4&&cmp2(s5,s6)) cout<<1;
	else cout<<0;
	if(c1==c2&&s3==s4&&cmp2(s5,s6)&&cmp(s5,s6))cout<<1;
	else cout<<0;
	return 0;
}
