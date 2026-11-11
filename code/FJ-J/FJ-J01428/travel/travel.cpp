#include<bits/stdc++.h>
#define int long long
using namespace std;
inline bool pp(char a,char b){
	if((a<'D'&&b<'D')||(a>='D'&&b>='D')){
		return true;
	}
	else{
		return false;
	}
}
inline bool p(char a,char b){
	if(abs(a-b)==1||((a=='D')&&(b=='F')||((a=='F')&&(b=='D')))){
		return true;
	}
	else{
		return false;
	}
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			if(pp(s1[2],s2[2])){
				cout<<1;
				if(p(s1[2],s2[2])){
					cout<<1;
				}
				else{
					cout<<"0";
				}
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	
	
	return 0;
}
