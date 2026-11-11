#include<bits/stdc++.h>
using namespace std;
long long a,b;
string s1,s2;
char x,y;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>a>>s1>>b>>s2;
	if(a!=b){
		cout<<"0000";
		return 0;
	}
	if(s1[0]!=s2[0]||s1[1]!=s2[1]){
		cout<<"1000";
		return 0;
	}
	x=s1[2];
	y=s2[2];
	if(x<'D'&&y>'C'){
		cout<<"1100";
		return 0;
	}
	if(x>'C'&&y<'D'){
		cout<<"1100";
		return 0;
	}
	if(x<'D'){
		if(y==x+1||y==x-1){
			cout<<"1111";
			return 0;
		}
		else{
			cout<<"1110";
			return 0;
		}
	}
	else{
		cout<<"1111";
		return 0;
	}
}
