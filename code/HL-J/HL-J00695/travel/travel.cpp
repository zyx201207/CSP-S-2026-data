#include<bits/stdc++.h>
using namespace std;
string a,b,a_1,b_1;
int l,l_1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>a_1>>b>>b_1;
	if(a==b) {
		cout<<1;
	}
	else {
		cout<<"0000";
		return 0;
	}
	if(a_1[2]=='A'||a_1[2]=='B'||a_1[2]=='C') l=1;
	else l=2;
	if(b_1[2]=='A'||b_1[2]=='B'||b_1[2]=='C') l_1=1;
	else l_1=2;
	if(a_1[0]==b_1[0]&&a_1[1]==b_1[1]){
		cout<<1;
		if(l==l_1) {
			cout<<1;
			if(a_1[2]==b_1[2]+1||a_1[2]==b_1[2]-1) cout<<1;
			else cout<<0;
		}
		else cout<<"00";
	}
	else cout<<"000";
	return 0;
}