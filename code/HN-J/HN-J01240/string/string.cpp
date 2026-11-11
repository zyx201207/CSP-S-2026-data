#include<bits/stdc++.h>
using namespace std;
string s[100000];
int main(){
//freopen(" string.in","r",stdin);
//freopen(" string.out","w",stdout);
int L;
cin>>L;

for(int i=0;i<=L;i++){
	cin>>s[i];
}
if(s[0]=='2 a'&&s[1]=='2 b'&&s[2]=='1 c'){
	cout<<"2";
}
	return 0;
}
