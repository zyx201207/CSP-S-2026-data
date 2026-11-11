#include <bits/stdc++.h>
using namespace std;
string a,b,c,d;
int s[11];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c) s[1]=1;
	else {
		for(int i=1;i<=4;i++) printf("%d",s[i]);
		return 0;
	}if(b[0]==d[0]&&b[1]==d[1]) s[2]=1;
	else {
		for(int i=1;i<=4;i++) printf("%d",s[i]);
		return 0;
	}if((b[2]<='C'&&b[2]>='A'&&d[2]<='C'&&d[2]>='A')||(b[2]>='D'&&b[2]>='D')) s[3]=1;
	else {
		for(int i=1;i<=4;i++) printf("%d",s[i]);
		return 0;
	}if(b[2]>='D'){
		s[4]=1;
	}else {
		if((char)b[2]-1==d[2]||(char)d[2]-1==b[2]) s[4]=1;
	}
	for(int i=1;i<=4;i++) printf("%d",s[i]);
	return 0;
} 
