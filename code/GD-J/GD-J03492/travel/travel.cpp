#include<bits/stdc++.h>
using namespace std;
string s1,c1,s2,c2;
bool a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	a=(c1==c2);//1
	if(a)b=(s1[1]==s2[1]&&s1[0]==s2[0]);//2
	if(b){
		if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))c=1;
		else if((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F'))c=1;
	}
	if(a){
		int n=(s1[0]-'0')*10+(s1[1]-'0');
		int m=(s2[0]-'0')*10+(s2[1]-'0');
		if(abs(m-n)==1&&s1[2]==s2[2])d=1;
		if(c){
			if((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F'))d=1;
			if(s1[2]=='A'){
				if(s2[2]=='B')d=1;
			}
			if(s1[2]=='B'){
				if(s2[2]=='A'||s2[2]=='C')d=1;
			}
			if(s1[2]=='C'){
				if(s2[2]=='B')d=1;
			}
		}
	}
	cout<<a<<b<<c<<d;
	return 0;
}
