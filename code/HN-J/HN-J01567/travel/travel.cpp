#include<bits/stdc++.h>
using namespace std;

string s;
int a[4]={1,1,1,1};

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	getline(cin,s);
	if(s[0]!=s[7]||s[1]!=s[8]) {
		a[0]=0;
		a[1]=0;
		a[2]=0;
		a[3]=0;
	}if(a[0]==1&&(s[3]!=s[10]||s[4]!=s[11])){
		a[1]=0;
		a[2]=0;
		a[3]=0;
	}if(a[1]==1&&!(s[5]=='A'&&(s[12]=='B'||s[12]=='C')||s[5]=='B'&&(s[12]=='A'||s[12]=='C')||s[5]=='C'&&(s[12]=='B'||s[12]=='A')||s[5]=='D'&&s[12]=='F'||s[5]=='F'&&s[12]=='D')){
		a[2]=0;
		a[3]=0;
	}if(a[2]==1&&!((s[5]=='A'||s[5]=='C')&&s[12]=='B'||s[5]=='B'&&(s[12]=='A'||s[12]=='C')||s[5]=='D'&&s[12]=='F'||s[5]=='F'&&s[12]=='D')){
		a[3]=0;
	}
	cout<<a[0]<<a[1]<<a[2]<<a[3];
	return 0;
}
