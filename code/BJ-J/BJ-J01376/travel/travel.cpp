#include<iostream>
#include<string>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(s1[2]=='F') s1[2]='E';
	if(s2[2]=='F') s2[2]='E';
	if(c1!=c2){
		cout<<"0000\n";
		return 0;
	}
	cout<<1;
	if(!(s1[0]==s2[0]&&s1[1]==s2[1])){
		cout<<"000\n";
		return 0;
	}
	cout<<1;
	if(!(('A'<=s1[2]&&s1[2]<='C'&&'A'<=s2[2]&&s2[2]<='C')||('D'<=s1[2]&&s1[2]<='E'&&'D'<=s2[2]&&s2[2]<='E'))){
		cout<<"00\n";
		return 0;
	}
	cout<<1;
	if(s1[2]==s2[2]-1||s1[2]-1==s2[2]){
		cout<<1<<'\n';
	}
	else cout<<0<<'\n';
	return 0;
}
