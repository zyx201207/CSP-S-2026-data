#include<iostream>
using namespace std;
bool ans[4];
bool check1(string s1,string s2){
	char a=s1[2],b=s2[2];
	if((a<='C'&&a>='A')&&(b>='A'&&b<='C'))return 1;
	if((a=='D'&&b=='F')||(a=='F'&&b=='D'))return 1;
	return 0;
}
bool check2(string s1,string s2){
	if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A'))return 1;
	if((s1[2]=='B'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='B'))return 1;
	if((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D'))return 1;
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]==c2[0]&&c1[1]==c2[1])ans[0]=1;
	if(ans[0]&&s1[0]==s2[0]&&s1[1]==s2[1])ans[1]=1;
	if(ans[1]&&check1(s1,s2))ans[2]=1;
	if(ans[2]&&check2(s1,s2))ans[3]=1;
	for(int i=0;i<4;i++)cout<<ans[i];
	return 0;
}
