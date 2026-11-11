#include<bits/stdc++.h>
using namespace std;
int a,b,q1,q2,q3,q4;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>s1>>b>>s2;
	if(a==b){
		q1=1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			q2=1;
			if(((s1[2]=='A'||(s1[2]=='B'||s1[2]=='C'))&&(s2[2]=='A'||(s2[2]=='B'||s2[2]=='C')))||((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F'))){
				q3=1;
				if((s1[2]=='A'||s1[2]=='B')&&(s2[2]=='A'||s2[2]=='B')||(s1[2]=='C'||s1[2]=='B')&&(s2[2]=='C'||s2[2]=='B')||(s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F')){
					q4=1;
				}
			}
		}
	}
	cout<<q1<<q2<<q3<<q4;
	return 0;
} 
