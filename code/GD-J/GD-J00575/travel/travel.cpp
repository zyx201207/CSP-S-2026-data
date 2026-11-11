#include <bits/stdc++.h>
#define int long long
using namespace std;
string s;
string s1;
string num;
string num1;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s>>num>>s1>>num1;
	if(s==s1){
		cout<<1;
		if(num[0]==num1[0]&&num[1]==num1[1]){
			cout<<1;
			if((num[2]-'A'<3&&num1[2]-'A'<3)||(num[2]-'A'>=3&&num1[2]-'A'>=3)){
				cout<<1;
				if(abs(num[2]-num1[2])==1){
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
