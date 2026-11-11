#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
bool ans;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		ans = 1;
		cout<<1;
	}else cout<<0;
	if(ans&&s1[0]==s2[0]&&s1[1]==s2[1]) cout<<1;
	else{
		ans = 0;
		cout<<0;
	}if(ans&&((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D'))) cout<<1;
	else{
		ans = 0;
		cout<<0;
	}if(!ans) cout<<0;
	else if(s1[2]>='D'&&s2[2]>='D') cout<<1;
	else{
		if((s1[2]=='A'||s2[2]=='A')&&(s1[2]=='B'||s2[2]=='B')) cout<<1;
		else if((s1[2]=='C'||s2[2]=='C')&&(s1[2]=='B'||s2[2]=='B')) cout<<1;
		else cout<<0;
	}return 0;
}
