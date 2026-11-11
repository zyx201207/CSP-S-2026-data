#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		char a=s1[2],b=s2[2];
		s1=s1.substr(0,2);
		s2=s2.substr(0,2);
		if(s1==s2){
			cout<<1;
			if(a<'D'&&b<'D'){
				cout<<1;
				if(abs(a-b)==1) cout<<1;
				else cout<<0;
			}else if(a>'C'&&b>'C'){
				cout<<"11";
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	cout<<endl;
	return 0;
}
