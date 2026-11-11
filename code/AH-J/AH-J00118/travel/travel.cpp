#include <bits/stdc++.h>
using namespace std;
int c1,c2,s1a,s2a,s1b,s2b;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	s1a=(s1[0]-'0')*10+s1[1]-'0';
	s1b=s1[2]-'A'+1;
	s2a=(s2[0]-'0')*10+s2[1]-'0';
	s2b=s2[2]-'A'+1;
	if (c1==c2){
		cout<<1;
		if (s1a==s2a){
			cout<<1;
			if (s1b<=3 && s2b<=3 || s1b>=4 && s2b>=4){
				cout<<1;
				if (s1b>s2b) swap(s1b,s2b);
				if (s1b==4){
					if (s2b==6) cout<<1;
					else cout<<0;
				}
				else if (s2b-s1b==1 && s1b!=3) cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
