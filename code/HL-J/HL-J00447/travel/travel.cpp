#include<bits/stdc++.h>
using namespace std;
char a[100],b[100];
int main(){
	int c1,c2;
	string s1,s2;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<1;
	else {
		cout<<"0000";
		return 0;
	}
	int t=0;
	for(int i=0;i<2;i++){
		if(s1[i]==s2[i]){
			t=0;
		}else{
			cout<<"000";
			return 0;
		}
	}
	if(t==0) cout<<1;
	char A1,B1;
	for(int i=0;i<s1.size();i++){
		if('A'<=s1[i]&&s1[i]<='F'){
			A1=s1[i];
		}
	}
	for(int i=0;i<s2.size();i++){
		if('A'<=s2[i]&&s2[i]<='F'){
			B1=s2[i];
		}
	}
	if('A'<=A1&&A1<='C'&&'A'<=B1&&B1<='C'){
		cout<<1;
	}else if('D'<=A1&&A1<='F'&&'D'<=B1&&B1<='F'){
		cout<<"11";
	}else{
		cout<<"00";
	}
	if('A'==A1&&B1=='B') {
		cout<<1;
	}
	if('B'==A1&&B1=='C'||'B'==A1&&B1=='A') {
		cout<<1;
	}
	if('C'==A1&&B1=='B') {
		cout<<1;
	}
	if('C'==A1&&B1=='A'||'A'==A1&&B1=='C') {
		cout<<0;
	}
	return 0;
}
