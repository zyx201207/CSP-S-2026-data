#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int num1,num2;
char P1,P2;
void solve(char A,char B){
	if((A=='A'&&B=='C')||(A=='C'&&B=='A'))
		cout<<0;
	else cout<<1;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000\n";
		return 0;
	}
	num1=(s1[0]-'0')*10+s1[1]-'0';
	num2=(s2[0]-'0')*10+s2[1]-'0';
	if(num1!=num2){
		cout<<"1000\n";
		return 0;
	}
	P1=s1[2],P2=s2[2];
	cout<<11;
	if(P1<='C'){
		if(P2<='C'){
			cout<<1;
			solve(P1,P2);
		}
		else cout<<"00";
	}
	else if(P2>'C'){
		cout<<1;
		solve(P1,P2);
	}
	else cout<<"00";
	return 0;
}
