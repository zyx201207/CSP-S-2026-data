#include<bits/stdc++.h>
using namespace std;
string c,s,cc,ss;
bool h[100][100];
bool k[100][100];
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >>c >> s >> cc >> ss;
	if(c != cc){
		cout << "0000";
		return 0;
	}
	if((s[0]-'0')*10+(s[1]-'0') != (ss[0]-'0')*10+(ss[1]-'0')){
		cout << "1000";
		return 0;
	}
	h['F'-'A']['D'-'A'] = 1;
	h['D'-'A']['F'-'A'] = 1;
	h['C'-'A']['B'-'A'] = 1;
	h['B'-'A']['C'-'A'] = 1;
	h['B'-'A']['A'-'A'] = 1;
	h['A'-'A']['B'-'A'] = 1;
	k['A'-'A']['C'-'A'] = 1;
	k['C'-'A']['A'-'A'] = 1;
	if(h[s[2]-'A'][ss[2]-'A']){
		cout << "1111";
	}else if(k[s[2]-'A'][ss[2]-'A']){
		cout << "1110";
	}else{
		cout << "1100";
	}
	return 0;
} 
