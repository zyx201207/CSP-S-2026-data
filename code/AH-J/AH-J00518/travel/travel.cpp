#include <bits/stdc++.h>
using namespace std;
#define int long long
string s1,s2,c1,c2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s1>>s2>>c1>>c2;
	if(s1==c1){
		cout<<'1';
		if(s2[0]==c2[0]&&s2[1]==c2[1]){
			cout<<'1';
			if((s2[2]=='A'&&(c2[2]=='B'||c2[2]=='C'))||(s2[2]=='B'&&(c2[2]=='A'||c2[2]=='C'))||(s2[2]=='C'&&(c2[2]=='B'||c2[2]=='A'))||(s2[2]=='D'&&c2[2]=='E')||(s2[2]=='E'&&c2[2]=='D')){
				cout<<'1';
				if(abs(s2[2]-c2[2])==1){
					cout<<'1';
				}else{
					cout<<"0";
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}//100
