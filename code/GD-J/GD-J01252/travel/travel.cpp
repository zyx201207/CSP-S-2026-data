#include<iostream>
#include<cstdio>
using namespace std;
int f(string s){
	if(s[2]=='A'||s[2]=='B'||s[2]=='C')return 1;
	else return 2;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]==c2[0]&&c1[1]==c2[1]){
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			if(f(s1)==f(s2)){
				if(f(s1)==2||s1[2]=='B'||s2[2]=='B')cout<<"1111";
				else cout<<"1110";
			}
			else cout<<"1100";
		}
		else cout<<"1000";
	}
	else cout<<"0000";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
