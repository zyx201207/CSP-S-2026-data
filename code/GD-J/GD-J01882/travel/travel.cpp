#include<bits/stdc++.h>
using namespace std;
bool fun(char s) {
	if(s=='F'||s=='D')return 1;
	else return 0;
}
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin >>c1>>s1>>c2>>s2;
	if(c1==c2) {
		cout <<1;
		string get1=s1.substr(0,2),get2=s2.substr(0,2);
		if(get1==get2) {
			cout <<1;
			get1=s1.substr(2,1),get2=s2.substr(2,1);
			if((fun(get1[0])&&fun(get2[0]))||(!fun(get1[0])&&!fun(get2[0]))) {
				cout <<1;
				if((fun(get1[0])&&fun(get2[0]))||(abs(get1[0]-get2[0])==1&&get1[0]<'D'&&get2[0]<'D')) {
					cout <<1;
				} else cout <<0;
			} else cout <<"00";
		} else cout <<"000";
	} else cout <<"0000";
	return 0;
}

