#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	bool flg1=1,flg2=1;
	if (c1==c2){
		cout << 1;
	}else{
		cout << 0;
		flg1=0;
	}if (s1[0]==s2[0] && s1[1]==s2[1] && flg1){
		cout << 1;
	}else{
		cout << 0;
		flg2=0;
	}if (((s1[2]<='C' && s2[2]<='C') || (s1[2]>='D' && s2[2]>='D')) && flg1 && flg2){
		cout << 1;
	}else{
		cout << 0;
	}if (c1==c2 && (s1[0]==s2[0] && s1[1]==s2[1]) && abs(s1[2]-s2[2])==1){
		if ((s1[2]=='C' && s2[2]=='D') || (s1[2]=='D' && s2[2]=='C')){
			cout << 0;
		}else{
			cout << 1;
		}
	}else{
		if ((s1[2]=='D' && s2[2]=='F') || (s1[2]=='F' && s2[2]=='D')){
			cout << 1;
		}else{
			cout << 0;
		}
	}
	return 0;
}
