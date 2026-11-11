#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,c1,s2,c2;cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
	}else{
		cout<<"1";
		if((s1[0]==s2[0])&&(s1[1]==s2[1])){
			cout<<"1";
			int n1=int(s1[2])-64,n2=int(s2[2])-64;
			if((n1<=3)&&(n2<=3)){
				cout<<"1";
				if(abs(n1-n2)==1)cout<<"1";
				else cout<<"0";
			}else if((n1>3)&&(n2>3)){
				cout<<"11";
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}
	return 0;
}
