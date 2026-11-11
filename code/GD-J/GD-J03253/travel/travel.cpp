#include<iostream>
using namespace std;
string c1,s1,c2,s2;
bool check(char a,char b){
	if(a>b){
		char t=a;
		a=b,b=t;
	}
	if(a<='C') return a+1==b;
	else return a+2==b;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2) cout<<"0000";
	else{
		if(s1[0]!=s2[0]||s1[1]!=s2[1]) cout<<"1000";
		else{
			if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='D'&&s2[2]<='F'||s2[2]>='A'&&s2[2]<='C'&&s1[2]>='D'&&s1[2]<='F') cout<<"1100";
			else{
				if(check(s1[2],s2[2])) cout<<"1111";
				else cout<<"1110";
			}
		}
	}
	return 0;
}
