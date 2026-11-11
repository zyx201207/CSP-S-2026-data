#include <bits/stdc++.h>
#define int long long
#define max(a,b) (a>b? a:b)
#define min(a,b) (a<b? a:b)
using namespace std;

string c1,s1,c2,s2;
bool check(char c){
	if((c=='A') || (c=='B') || (c=='C')){
		return true;
	}
	return false;
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1!=c2){
		cout << "0000" << endl;
	}else if((s1[0]!=s2[0]) || (s1[1]!=s2[1])){
		cout << "1000" << endl;
	}else if(check(s1[2])!=check(s2[2])){
		cout << "1100" << endl;
	}else if(abs(s1[2]-s2[2])>1){
		cout << "1110" << endl;
	}else{
		cout << "1111" << endl;
	}
	return 0;
}
