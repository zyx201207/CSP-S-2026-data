/*
I AK CSP!!!
I AK CSP!!!
I AK CSP!!!
*/
//100+100+55+48=303pts
//100pts
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	int rc,xc,rs,xs;
	rc=(int)(c1[0]-'0')*10+(int)(c1[1]-'0');
	xc=(int)(c2[0]-'0')*10+(int)(c2[1]-'0');
	rs=(int)(s1[0]-'0')*10+(int)(s1[1]-'0');
	xs=(int)(s2[0]-'0')*10+(int)(s2[1]-'0');
	if(rc!=xc){
		cout<<"0000";
		return 0;
	}
	if(rs!=xs){
		cout<<"1000";
		return 0;
	}
	if(s1[2]=='A'){
		if(s2[2]=='F'||s2[2]=='D'){
			cout<<"1100";
			return 0;
		}
		if(s2[2]=='C'){
			cout<<"1110";
			return 0;
		}
		cout<<"1111";
	}else if(s1[2]=='B'){
		if(s2[2]=='F'||s2[2]=='D'){
			cout<<"1100";
			return 0;
		}
		cout<<"1111";
	}else if(s1[2]=='C'){
		if(s2[2]=='F'||s2[2]=='D'){
			cout<<"1100";
			return 0;
		}
		if(s2[2]=='A'){
			cout<<"1110";
			return 0;
		}
		cout<<"1111";
	}else if(s1[2]=='D'){
		if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
			cout<<"1100";
			return 0;
		}
		cout<<"1111";
	}else if(s1[2]=='F'){
		if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
			cout<<"1100";
			return 0;
		}
		cout<<"1111";
	}
	return 0;
}
/*
I AK CSP!!!
I AK CSP!!!
I AK CSP!!!
*/ 
