#include <bits/stdc++.h>
using namespace std;
set<int> c;
int c1,c2;
string s1,s2;

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1 == c2){
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			bool flag = false;
			if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
				if(s2[2]=='D'||s2[2]=='F') cout<<0<<0;
				else{
					cout<<1;
					flag = true;
				}
			}
			else{
				if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C') cout<<0<<0;
				else{
					cout<<1;
					flag = true;
				}
			}
			if(flag){
				if(abs(s1[2]-s2[2])==1) cout<<1;
				else cout<<0;
			}
		}
		else{
			cout<<0<<0<<0;
		}
	}
	else cout<<0<<0<<0<<0;
	
	return 0;
}
