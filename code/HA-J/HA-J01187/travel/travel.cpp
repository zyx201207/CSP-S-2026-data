#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	int n=(s1[0]-'0')*10+(s1[1]-'0');
	char s=s1[2];
	int m=(s2[0]-'0')*10+(s2[1]-'0');
	char c=s2[2];
	if(n==m){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if((s=='D'&&c=='F')||(c=='D'&&s=='F')||(c=='A'&&s=='B')||(c=='A'&&s=='C')||(c=='B'&&s=='C')||(c=='B'&&s=='A')||(c=='C'&&s=='B')||(c=='C'&&s=='A')){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if((s=='D'&&c=='F')||(c=='D'&&s=='F')||(c=='A'&&s=='B')||(c=='B'&&s=='C')||(c=='B'&&s=='A')||(c=='C'&&s=='B')){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
