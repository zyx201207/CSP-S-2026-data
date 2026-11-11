#include<bits/stdc++.h>
using namespace std;
int c1,s1;
double c2[3],s2[3];
int main(){
	scanf("%lf",c1,c2,s1,c2);
	if(c1==s1){
		cout<<11;
		if(c2[0]==s2[0]||c2[1]==s2[1]){
			if((c2[2]=='A'||c2[2]=='B'||c2[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')){
				cout<<"11";
			}
			else if((c2[2]=='D'||c2[2]=='F')&&(c2[2]=='D'||c2[2]=='F')){
				cout<<"11"; 
			}
		}
		else cout<<"10";
	}
	else cout<<"10";
	return 0;
}
