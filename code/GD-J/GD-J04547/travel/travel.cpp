#include<bits/stdc++.h>
using namespace std;
using ll = long long ;
const int N = 1e5+5;
char s[N],S[N],c[N],C[N];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for(ll i=0;i<2;i++) cin>>c[i];
	for(ll i=0;i<3;i++){
		cin>>s[i];
	}
	for(ll i=0;i<2;i++) cin>>C[i];
	for(ll i=0;i<3;i++){
		cin>>S[i];
	}
//	cout<<s[0]<<' '<<s[1]<<' '<<s[2]<<'\n';
//	cout<<S[0]<<' '<<S[1]<<' '<<S[2]<<'\n';
	if(c[0]==C[0]&&c[1]==C[1]) {
		cout<<1;
		if(s[0]==S[0]&&s[1]==S[1]){
			cout<<1;
			if(s[2]=='A'||s[2]=='B'||s[2]=='C'&&S[2]=='A'||S[2]=='B'||S[2]=='C'){
				cout<<1;
				if(s[2]+1==S[2]||s[2]-1==S[2]){
					cout<<1;
				}
				else {
					cout<<0;
					return 0;
				}
			}	
			else if(s[2]=='D'||s[2]=='E'&&S[2]=='D'||S[2]=='E'){
				cout<<"11";
				return 0;
			}
			else {
				cout<<"00";
				return 0;
			}
		}else{
			cout<<"000";
			return 0;
		} 
	}
	else {
		cout<<"0000";
	}
	
	return 0;
}
