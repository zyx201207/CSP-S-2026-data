#include<iostream>
#include<string>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string c1,s1,c2,s2;
	char r,x;
	bool flag=0;
	cin>>c1>>s1>>c2>>s2;
	r=s1[2];
	x=s2[2];
	if(c1==c2){
		cout<<1;
	}
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(s1[0]==s2[0] && s1[1]==s2[1]){
		cout<<1;
	}
	else{
		cout<<0<<0<<0;
		return 0;
	}
	if(((('A'<=x && x<='C' && 'A'<=r && r<='C') || ('D'<=x && x<='E' && 'D'<=r && r<='E')))){
		cout<<1;
	}
	else{
		cout<<0<<0;
		return 0;
	}
	if(abs((int)(x)-(int)(r))==1 && !(((x=='C' && r=='D') || (x=='D' && r=='C')))){
		cout<<1;
	}
	else cout<<0;
	return 0;
}
