#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll m,n;
string s,t;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>m>>s>>n>>t;
	if(m==n){
		cout<<"1";
		if(s[0]==t[0]&&s[1]==t[1]){
			cout<<"1";
			if(s[2]<=67&&s[2]>=65&&t[2]<=67&&t[2]>=65){
				cout<<"1";
				if(s[2]==t[2]+1||s[2]==t[2]-1){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}else if(s[2]==70&&t[2]==68){
				cout<<"11";
				return 0;
			}else if(t[2]==70&&s[2]==68){
				cout<<"11";
				return 0;
			}else{
				cout<<"00";
				return 0;
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
