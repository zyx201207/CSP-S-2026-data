#include<bits/stdc++.h>
using namespace std;
int t[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	getline(cin,s);
	if((s[0]==s[7])&&(s[1]==s[8])){
		t[1]=1;
	}
	if((s[3]==s[10])&&(s[4]==s[11])&&(t[1]==1)){
		t[2]=1;
	}
	if((((s[5]<='C')&&(s[12]<='C'))||((s[5]>'C')&&(s[12]>'C')))&&(t[2]==1)){
		t[3]=1;
	}
	if((((abs(s[5]-s[12])))==1)&&(t[3]==1)){
		t[4]=1;
	}
	for(int i=1;i<=4;i++)cout<<t[i];
	return 0;
}

