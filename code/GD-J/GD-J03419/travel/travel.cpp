#include<bits/stdc++.h>
using namespace std;
int a[11],b[11];
int t,e;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	string c;
	string s;
	string n;
	string m;
	cin>>c>>s>>n>>m;
	if(c == n){
		cout<<'1';
	}
	else{
		cout<<"0000";
		return 0;
	}
	bool has = 1;
	if(s[0] == m[0] && s[1] == m[1]){
		cout<<'1';
	}
	else{
		has = 0;
		cout<<'0';
	}
	bool k = 1;
	if(has == 0){
		cout<<'0';
	}
	else{
		if(s[2] >= 'A' && s[2] <= 'C' && m[2] >= 'A' && m[2] <= 'C'){
			cout<<'1';
		}
		else if(s[2] >= 'D'&&s[2] <= 'F' && m[2] >= 'D' && m[2] <= 'F'){
			cout<<'1';
		}
		else{
			k = 0;
			cout<<'0';
		}
	}
	if(has == 0 || k == 0){
		cout<<'0';
	}
	else{
		if(s[2] == 'D' && m[2] == 'F' || s[2] == 'F'&& m[2] == 'D'){
			cout<<'1';
			return 0;
		}
		else if(s[2] == 'C' && m[2] == 'D' || s[2] == 'D'&& m[2] == 'C'){
			cout<<'0';
			return 0;
		}
		else{
		a[0] = s[2];
		b[0] = m[2];
		int ma = max(a[0],b[0]);
		int mi = min(a[0],b[0]);
		if(ma - mi == 1){
			cout<<'1';
			return 0;
		}
		else{
			cout<<'0';
			return 0;
		}
		}
	}
	return 0;
}
