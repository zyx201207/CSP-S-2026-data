#include<bits/stdc++.h>
using namespace std;
char c1[3],c2[3],s1[4],s2[4];
int f;
bool s(char *a,char *b){
	for(int i=0;i<2;i++){
		if(a[i]!=b[i]) return 0;
	}return 1;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	cout<<s(c1,c2);
	if(s(c1,c2)&&s1[0]==s2[0]&&s1[1]==s2[1]) cout<<1;
	else cout<<0;
	if(s(c1,c2)&&s1[0]==s2[0]&&s1[1]==s2[1]&&(((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))||((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F')))){
		cout<<1;
	}else cout<<0;
	if(s(c1,c2)&&s1[0]==s2[0]&&s1[1]==s2[1]){
		if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')){
			f=1;
		}
	}
	cout<<f;
	return 0;
}
