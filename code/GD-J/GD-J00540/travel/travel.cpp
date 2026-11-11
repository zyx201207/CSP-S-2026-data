#include<bits/stdc++.h>
#define fre(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout)
using namespace std;
string a,b,c,d;
int f;
int main()
{
	fre("travel");
	cin>>a>>b>>c>>d;
	if(a==c) cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
	if(b[0]==d[0]&&b[1]==d[1]){
		cout<<"1";
		if(b[2]=='A'||b[2]=='B'||b[2]=='C'){
			if(d[2]=='A'||d[2]=='B'||d[2]=='C') cout<<"1";
			else{
				cout<<"00";
				return 0;
			}
		}
		if(b[2]=='D'||b[2]=='F'){
			if(d[2]=='D'||d[2]=='F'){
				cout<<"1";
			}
			else{
				cout<<"00";
				return 0;
			}
		}
	}else{
		cout<<"000";
		return 0;
	}
	f=abs(int(b[2]-d[2]));
	if(b[2]=='D'&&d[2]=='C'||b[2]=='C'&&d[2]=='D'){
		cout<<"0";
		return 0;
	}
	if(f==1) cout<<"1";
	else cout<<"0";
} 
