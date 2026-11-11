#include<bits\stdc++.h>
using namespace std;
string s[5],a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s[1]>>s[2]>>s[3]>>s[4];
	if(s[1]==s[3])cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	for(int i=0;i<=1;i++){
		a+=s[2][i];
		b+=s[4][i];
	}
	if(a==b)cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	a=s[2][2];
	b=s[4][2];
	int c=int(a[0]-'A')+1,d=int(b[0]-'A')+1;
	if((c>3&&d>3)||(c<4&&d<4))cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if(abs(c-d)==1)cout<<1;
	else{
		cout<<"0";
		return 0;
	}
	return 0;
}
/*
02 01A 02 01B
02 01C 02 01A
02 01C 02 01D
02 02B 02 01A
02 01A 03 01A
*/
