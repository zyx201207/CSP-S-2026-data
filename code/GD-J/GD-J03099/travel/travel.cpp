#include<bits/stdc++.h>
using namespace std;

string a,b,c,d;
string ans = "zzzz";
bool q1 = 0;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> b >> c >> d;
	if(a == c){
		ans[0] = '1';
	}
	else{
		ans = "0000";
		cout << ans;
		return 0;
	}
	if(b[0] == d[0] && b[1] == d[1]){
		ans[1] = '1';
	}
	else{
		ans = "1000";
		cout << ans;
		return 0;
	}
	if((b[2] == 'A' || b[2] == 'B' || b[2] == 'C') && (d[2] == 'A' || d[2] == 'B' || d[2] == 'C')){
		ans[2] = '1';
		q1 = 1;
	}
	else if((b[2] == 'F' || b[2] == 'D') && (d[2] == 'F' || d[2] == 'D')){
		ans[2] = '1';
	}
	else{
		ans = "1100";
		cout << ans;
		return 0;
	}
	if(b[2] - 1 == d[2] || b[2] + 1 == d[2]){
		ans[3] = '1';
	}
	else if(!q1){
		ans[3] = '1';
	}
	else{
		ans = "1110";
		cout << ans;
		return 0;
	}
	cout << ans;
	return 0;
}
