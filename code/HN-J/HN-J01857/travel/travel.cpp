#include<bits/stdc++.h>
//#define int long long
using namespace std;
string c,s;
int x,y,l,r;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x>>s>>y>>c;
	l=s[1]-'0'+10*(s[0]-'0');
	r=c[1]-'0'+10*(c[0]-'0');
	if(x!=y){
		cout<<"0000";
		return 0;
	}else{
		cout<<"1";
		if(l==r){
			cout<<"1";
			if(s[2]=='A'){
				if(c[2]=='B')cout<<"11";
				else if(c[2]=='C')cout<<"10";
				else cout<<"00";
			}else if(s[2]=='B'){
				if(c[2]=='A'||c[2]=='C')cout<<"11";
				else cout<<"00";
			}else if(s[2]=='C'){
				if(c[2]=='B')cout<<"11";
				else if(c[2]=='A')cout<<"10";
				else cout<<"00";
			}else if(s[2]=='F'){
				if(c[2]=='D')cout<<"11";
				else cout<<"00";
			}else if(s[2]=='D'){
				if(c[2]=='F')cout<<"11";
				else cout<<"00";
			}
		}else{
			cout<<"000";
			return 0;
		}
	}
	return 0;
}

