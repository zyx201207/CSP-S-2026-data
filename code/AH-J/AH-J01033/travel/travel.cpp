#include<bits/stdc++.h>
using namespace std;
bool judge1(string s,string t){
	char a = s[2],b = t[2];
	if((a == 'F' || a == 'D')&&(b == 'F' || b == 'D')){
		return 1;
	}else if((a == 'A' || a == 'B'|| a == 'C')&&(b == 'A' || b == 'B' || b == 'C' )){
		return 1;
	}
	return 0;
}
bool judge2(string s,string t){
	char a = s[2],b = t[2];
	if((a == 'F' || a == 'D')&&(b == 'F' || b == 'D')){
		return 1;
	}else if((a == 'A' || a == 'B'|| a == 'C')&&(b == 'A' || b == 'B' || b == 'C' )){
		if(abs(a - b) == 1){
			return 1;
		}
	}
	return 0;
}
int main(){
	//ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string a1,b1;
	cin >> a >> a1 >> b >> b1;
	if(a == b)cout << 1;
	else cout << 0;
	if(a1[0] == b1[0] && a1[1] == b1[1]){
		cout << 1;
	}else cout << 0;
	if(a1[0] == b1[0] && a1[1] == b1[1] && judge1(a1,b1)){
		cout << 1;
	}else cout << 0;
	if(a1[0] == b1[0] && a1[1] == b1[1] && judge1(a1,b1)&&judge2(a1,b1)){
		cout << 1;
	}else cout << 0;
	return 0;
}

