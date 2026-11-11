#include<bits/stdc++.h>
using namespace std;
int a,b;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>a>>s1>>b>>s2;
	if(a!=b){
		cout<<"0000";
		return 0;
	}
	cout<<1;
	if(s1[0]!=s2[0]||s1[1]!=s2[1]){
		cout<<"000";
		return 0;
	}
	cout<<1;
	if((s1[2]-'A'<=2&&s2[2]-'A'>2)||(s1[2]-'A'>2&&s2[2]-'A'<=2)){
		cout<<"00";
		return 0;
	}
	cout<<1;
	if(((s1[2]-'A'<=2&&s2[2]-'A'<=2)||(s1[2]-'A'>2&&s2[2]-'A'>2))&&(s1[2]+1==s2[2]||s1[2]-1==s2[2])){
		cout<<1;
		return 0;
	}
	cout<<0;
	return 0;
}
