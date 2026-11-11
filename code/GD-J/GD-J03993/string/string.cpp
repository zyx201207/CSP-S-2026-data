#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	cin>>s;
	int a=s.size();
	if(a==1) cout<<0;
	else if(a==2) {
		if(s[0]==s[1]) cout<<0;
		else cout<<1;
	}
    return 0;
}
