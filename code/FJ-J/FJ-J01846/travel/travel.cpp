#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		if(s1[0]==s2[0] && s1[1]==s2[1]){
			cout<<1;
			if('A'<=s1[2] && s1[2]<='C' && 'A'<=s2[2] && s2[2]<='C'){
				cout<<1;
				if(abs(int(s1[2]-s2[2]))==1)cout<<1;
				else cout<<0;
			}
			else if(('D'==s1[2] && s2[2]=='F') || ('D'==s2[2] && s1[2]=='F'))cout<<"11";
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
