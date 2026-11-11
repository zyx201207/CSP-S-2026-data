#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

string s;
int c1,c2,c3,s1,s2,s3;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s;
	c1 = s[1]-'0'+(s[0]-'0')*10;
	cin>>s;
	c2 = s[1]-'0'+(s[0]-'0')*10;
	c3 = s[2]-'A';
	cin>>s;
	s1 = s[1]-'0'+(s[0]-'0')*10;
	cin>>s;
	s2 = s[1]-'0'+(s[0]-'0')*10;
	s3 = s[2]-'A';
	if(c1 == s1) cout<<1;
	else cout<<0;
	
	if(c1 == s1 && c2 == s2){
		cout<<1;
		if(c3 <= 2 && s3 <= 2) cout<<1;
		else if(c3 >= 3 && s3 >= 3) cout<<1;
		else cout<<0;
	}
	else{
		cout<<"00";
	}
	
	
	if(c1 == s1 && c2 == s2){
		if(c3 <= 2 && s3 <= 2 && abs(c3-s3) == 1){
			cout<<1;
		}
		else if(c3 >= 3 && s3 >= 3 && abs(c3-s3) == 1) cout<<1;
		else cout<<0;
	}
	else cout<<0;
	return 0;
}
