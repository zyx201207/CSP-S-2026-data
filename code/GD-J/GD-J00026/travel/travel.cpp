#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3) cout<<1;
	else{
		cout<<"0000\n";
		return 0;
	}
	if((s1==s3)&&(s2[0]==s4[0])&&(s2[1]==s4[1])) cout<<1;
	else{
		cout<<"000\n";
		return 0;
	}
	
	int x=s2[2]-'A';
	int y=s4[2]-'A';
	if(((x<=2)&&(y<=2))||((x>2)&&(y>2))){
		if(abs(x-y)==1) cout<<"11\n";
		else cout<<"10\n";
	}
	else cout<<"00\n";
	return 0;
}
