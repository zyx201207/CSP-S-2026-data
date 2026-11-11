#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4; cin >> s1 >> s2 >> s3 >> s4;
	bool f1=0,f2=0,f3=0,f4=0;
	if(s1==s3) f1=1;
	if(f1 && s2[0]==s4[0] && s2[1]==s4[1]) f2=1;
	if(f2 && ((s2[2]<='C' && s4[2]<='C') || (s2[2]>='D' && s4[2]>='D'))) f3=1;
	if(f3 && abs(s2[2]-s4[2])==1) f4=1;
	if(f1) cout << 1;
	else cout << 0;
	if(f2) cout << 1;
	else cout << 0;
	if(f3) cout << 1;
	else cout << 0;
	if(f4) cout << 1;
	else cout << 0;
	
	
	return 0;
}
