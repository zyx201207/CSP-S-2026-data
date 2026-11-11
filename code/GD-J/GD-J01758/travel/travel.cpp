#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool x(char c,char cc){
	if(c>='A'&&c<='C'&&cc>'C')return 0;
	return 1;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)cout<<1;
	else{cout<<"0000";return 0;
	}if(s2[0]==s1[0]&&s2[1]==s1[1])cout<<1;
	else{cout<<"000";return 0;
	}if(x(s1[2],s2[2])&&x(s2[2],s1[2]))cout<<1;
	else{cout<<"00";return 0;
	}if(abs(s1[2]-s2[2])==1)cout<<1;
	else cout<<0;
	return 0;
}
