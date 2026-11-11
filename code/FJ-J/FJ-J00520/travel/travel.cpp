#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			if(s1[2]<='C'&&s2[2]<='C'){
				cout<<1;
				int r1=s1[2],r2=s2[2];
				if(abs(r1-r2)==1) cout<<1;
				else cout<<0;
			}else if(s1[2]>'C'&&s2[2]>'C') cout<<"11";
			else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
}
