#include <bits/stdc++.h>
using namespace std;
int n1,n2;
string s1,s2;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n1>>s1>>n2>>s2;
	if(n1!=n2){
		cout<<"0000";
		return 0;
	}
	int x=(s1[0]-'0')*10+s1[1]-'0',y=(s2[0]-'0')*10+s2[1]-'0';
	if(x!=y){
		cout<<"1000";
		return 0;
	}
	if((s1[2]<='C'&&s2[2]>='D')||(s2[2]<='C'&&s1[2]>='D')){
		cout<<"1100";
		return 0;
	}
	if(s1[2]==s2[2]-1||s1[2]==s2[2]+1){
		cout<<"1111";
		return 0;
	}
	cout<<"1110";
	return 0;
}
