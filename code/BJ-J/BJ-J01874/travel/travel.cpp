#include<bits/stdc++.h>
using namespace std;
string s11,s22,s33,s44;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s11>>s22>>s33>>s44;
	if(s11==s33)cout<<1;
	else cout<<0;
	if(s22[0]==s44[0] && s22[1]==s44[1])cout<<1;
	else cout<<0;
	if(s22[2]>'C' && s44[2]>'C')cout<<1;
	else if(s22[2]<'D' && s44[2]<'D')cout<<1;
	else cout<<0;
	if(min(s22[2],s44[2])=='D' and max(s22[2],s44[2])=='F')cout<<1;
	else if(min(s22[2],s44[2])+1==max(s22[2],s44[2]) and min(s22[2],s44[2])+1!='D')cout<<1;
	else cout<<0;
	return 0;
}
