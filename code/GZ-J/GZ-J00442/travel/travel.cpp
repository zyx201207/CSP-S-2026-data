//遵义市新蒲新区滨湖中学 金卓承 GZ-J00442 
#include<iostream>
#include<string>
#include<cmath>
using namespace std;
string s1,c1,s2,c2,ans;
string r1,r2;
bool check(char a,char b){
	return a=='C'&&b=='B'||a=='B'&&b=='A'||a=='D'&&b=='F'||a=='B'&&b=='C'||a=='A'&&b=='B'||a=='F'&&b=='D';
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>c1>>s2>>c2;
	ans="0000";
	if(s1==s2) ans[0]='1';
	char st1=c1[2],st2=c2[2];
	r1=c1.substr(0,2),r2=c2.substr(0,2);
	//cout<<st1<<'1'<<st2<<endl;
	if(r1==r2&&ans[0]=='1') ans[1]='1';
	
	if(ans[1]=='1'&&r1==r2&&((st1<='C'&&st2<='C')||(st1>='D'&&st2>='D'))) ans[2]='1';
	if(check(st1,st2)&&ans[2]=='1'){
		/*if(!(st1=='C'&&st2=='D'))*/ ans[3]='1';
	}
	cout<<ans;
	return 0;
}
