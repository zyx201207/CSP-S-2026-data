#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
bool p(string b,string d){
	if(b[2]=='A'||b[2]=='B'||b[2]=='C'){
		if(d[2]=='A'||d[2]=='B'||d[2]=='C'){
		    return 1;
	    }
	}else{
		if(d[2]=='D'||d[2]=='F'){
		    return 1;
	    }
	}return 0;
}
bool pp(string b,string d){
	char a=b[2],c=d[2];
	if(a=='A')if(c=='B')return true;
	if(a=='B')if(c=='A'||c=='c')return true;
	if(a=='C')if(c=='B')return true;
	if(a=='D')if(c=='F')return true;
	if(a=='F')if(c=='D')return true;
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>a>>b>>c>>d;
	if(a==c)cout<<1;
	else cout<<0;
	if(a==c&&b[0]==d[0]&&b[1]==d[1])cout<<1;
	else cout<<0;
	if(a==c&&b[0]==d[0]&&b[1]==d[1]&&p(b,d))cout<<1;
	else cout<<0;
	if(a==c&&b[0]==d[0]&&b[1]==d[1]&&p(b,d)&&pp(b,d))cout<<1;
	else cout<<0;
	return 0;
} 
