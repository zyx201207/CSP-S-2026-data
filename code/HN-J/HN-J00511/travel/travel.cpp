#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s1,k1;
	string s2,k2;
	cin>>s1>>k1>>s2>>k2;
	if(s1==s2){
		cout<<"1";
	} 
	else{
		cout<<"0000";
		return 0;
	}
	if(k1[0]==k2[0]&&k1[1]==k2[1]){
		cout<<"1";
		if(k1[2]=='A'||k1[2]=='B'||k1[2]=='C'){
			if(k2[2]=='A'||k2[2]=='B'||k2[2]=='C'){
				cout<<"1";
			}
			else{
				cout<<"0";
			}
		}
		else{
			if(k2[2]=='D'||k2[2]=='F'){
				cout<<"1";
			}
			else{
				cout<<"0";
			}
		}
	}
	else{
		cout<<"000";
		return 0;
	}
	if(k1[2]+1==k2[2]||k1[2]-1==k2[2]){
		if(k1[2]=='C'||k1[2]=='D'){
			cout<<"0";
		}
		else{
			cout<<"1";
		}
	}
	else{
		cout<<"0";
	}
	return 0;
}

