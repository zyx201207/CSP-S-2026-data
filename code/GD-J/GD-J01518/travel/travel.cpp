#include <bits/stdc++.h>
#define int long long
using namespace std;
string c1,s1,c2,s2;
bool v1=0,v2=0,v3=0,v4=0;
bool check(char x,char y){
	if(x>='A'&&x<='C'&&y>='A'&&y<='C'){
		if((x=='A'&&y=='C')||(x=='C'&&y=='A'))return 0;
	}
	return 1;
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>c1>>s1>>c2>>s2;
	if((c1[0]==c2[0])&&(c1[1]==c2[1])){
		v1=1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			v2=1;
			char x=s1[2],y=s2[2];
			if(x>='A'&&x<='C'&&y>='A'&&y<='C'){
				v3=1;
				if(check(x,y))v4=1;
			}else if(x>='D'&&x<='F'&&y>='D'&&y<='F'){
				v3=1;
				v4=1;
			}
		}
	}
	cout<<v1<<v2<<v3<<v4;
	return 0;
}
