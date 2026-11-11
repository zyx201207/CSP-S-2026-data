#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		if(s1[0]==s2[0] and s1[1]==s2[1]){
			if(s1[2]<='C' and s2[2]<='C'){
				if(s1[2]+'B'-'A'==s2[2] or s1[2]-'B'+'A'==s2[2]){
					cout<<"1111";
				}else cout<<"1110";
			}else if(s1[2]>'C' and s2[2]>'C'){
				cout<<"1111";
			}else cout<<"1100";
		}else cout<<"1000";
	}else cout<<"0000";
	return 0;
}
