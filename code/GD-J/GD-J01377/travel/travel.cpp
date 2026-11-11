#include <bits/stdc++.h>
#define int long long
using namespace std;
string c1,s1,c2,s2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) {
	cout<<'1';
    }else{
    	cout<<'0'<<'0'<<'0'<<'0';
    	return 0;
	}
	int i=1;
	if(s1[i-1]==s2[i-1]&&s1[i]==s2[i]){
		cout<<'1';
	}else{
		cout<<'0'<<'0'<<'0';
		return 0;
	}
	if(s1[i+1]=='A'){
		if(s2[i+1]=='B'){
			cout<<'1'<<'1';
		}else if(s2[i+1]=='C'){
			cout<<'1'<<'0';
		}else{
			cout<<'0'<<'0';
		}
	}
	if(s1[i+1]=='B'){
		if(s2[i+1]=='A'||s2[i+1]=='C'){
			cout<<'1'<<'1';
		}else{
			cout<<'0'<<'0';
		}
	}
	if(s1[i+1]=='C'){
		if(s2[i+1]=='A'){
			cout<<'1'<<'0';
		}else if(s2[i+1]=='B'){
			cout<<'1'<<'1';
		}else{
			cout<<'0'<<'0';
		}
	}
	if(s1[i+1]=='D'){
		if(s2[i+1]=='E'){
			cout<<'1'<<'1';
		}else{
			cout<<'0'<<'0';
		}
	}
	if(s1[i+1]=='E'){
		if(s2[i+1]=='D'){
			cout<<'1'<<'1';
		}else{
			cout<<'0'<<'0';
		}
	}
	
	return 0;
}
