#include<iostream>
#include<string>
using namespace std;
int c1,c2;
string s1,s2;
char ch1,ch2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	ch1=s1[2];
	ch2=s2[2];
	cout<<(c1==c2)<<(c1==c2 && s1[0]==s2[0] && s1[1]==s2[1]);
	if(c1==c2 && s1[0]==s2[0] && s1[1]==s2[1]){
		if(ch1<='C' && ch2<='C')cout<<1;
		else if(ch1>='D' && ch2>='D')cout<<1;
		else cout<<0;
	}
	else cout<<0;
	if(ch1<ch2)swap(ch1,ch2);
	if( c1==c2 && (s1[0]==s2[0] && s1[1]==s2[1]) && (ch1-ch2==1) && ( !( ch1=='D' && ch2=='C' ) ) )cout<<1;
	else cout<<0;
	return 0;
}
