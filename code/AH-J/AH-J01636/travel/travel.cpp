#include <bits/stdc++.h>
using namespace std;
string s1,s2,t1,t2;
int f(char p) {
	if(p=='A'||p=='B'||p=='C')
	return 1;
	else
	return 2;
}
bool cp(char p,char q) {
	return
	((p-q==1)||
	(q-p==1)||
	(p=='D'&&q=='F')||
	(p=='F'&&q=='D'))&&(f(p)==f(q));
}
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>t1>>t2;
	bool if1=0,if2=0,if3=0,if4=0;
	if1=(s1==t1);
	if2=(s2.substr(0,2)==t2.substr(0,2));
	if2&=if1;
	if3=(f(s2[2])==f(t2[2]));
	if3&=if2;
	if4=(cp(s2[2],t2[2]));
	if4&=if3;
	cout<<if1<<if2<<if3<<if4;
	return 0;
}

