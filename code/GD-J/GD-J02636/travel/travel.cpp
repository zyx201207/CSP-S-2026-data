#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
bool tyc(char a1,char a2){
	if(a1=='C'||a1=='A'||a1=='B'){
		return (a2=='C'||a2=='A'||a2=='B');
	}
	if(a1=='D'||a1=='E'){
		return (a2=='D'||a2=='E');
	}
}
bool tf1(){
	int ss1,ss2;
	ss1=(s1[0]-'0')*10+s1[1]-'0';
	ss2=(s2[0]-'0')*10+s2[1]-'0';
	int tf=abs(ss1-ss2);
	return (tf==1);
}
bool xl(){
	if(c1==c2){
		if((s1[0]==s2[0]&&s1[1]==s2[1]&&(abs(int(s1[2]-s2[2]))==1&&(!((s1[2]=='C'&&s2[2]=='B')||(s2[2]=='C'&&s1[2]=='B')))))||(s1[2]==s2[2]&&tf1())){
			return 1;
		}
	}
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	cout<<(c1==c2?1:0);
	cout<<((c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1])?1:0);
	cout<<(((c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1])&&tyc(s1[2],s2[2]))?1:0);
	cout<<xl();
	return 0;
} 
