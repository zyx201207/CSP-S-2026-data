#include <bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main(int argc, char** argv) {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(s1[0]*10+s1[1]==s2[0]*10+s2[1]){
		cout<<1;
	}else{
		cout<<0<<0<<0;
		return 0;
	}
	if(s1[2]==s2[2])
	return 0;
}
