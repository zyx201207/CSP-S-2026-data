#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool a=0,b=0,c=0;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]==c2[0]&&c2[1]==c1[1]){
		cout<<1;
		a=1;
	}
	else
		cout<<0;
	if(a==1&&(s1[0]==s2[0]&&s1[1]==s2[1])){
		cout<<1;
		b=1;
	} 
	else cout<<0;
	if(b==1&&(((s1[2]-'0'>=17&&s1[2]-'0'<=19)&&(s2[2]-'0'>=17&&s2[2]-'0'<=19))||((s1[2]-'0'>=20&&s1[2]-'0'<=21)&&(s2[2]-'0'>=20&&s2[2]-'0'<=21)))){
		c=1;
		cout<<1;
	}
	else
		cout<<0; 
	if(c==1&&abs((s1[2]-'0')-(s2[2]-'0'))<=1)
		cout<<1;
	else cout<<0;
	return 0;
	//02 01A 02 01B
	//02 01C 02 01A
} 
