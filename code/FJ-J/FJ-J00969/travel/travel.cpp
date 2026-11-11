#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	freopen("travel.in" , "r" , stdin);
	freopen("travel.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	char x , y;
	string c_1 , s_1 , c_2 , s_2;
	cin >> c_1 >> s_1 >> c_2 >> s_2;
	//cout<<c_1 <<" "<< s_1 <<" "<< c_2 << " " << s_2;
	if(c_1 == c_2) cout << 1;
	int cnt = 0 , ans = 0;
	for(int i = 0 ; i < s_1.size() ; i++){
		if(s_1[i] >= '0' && s_1[i] <= '9'){
			cnt = cnt*10 + s_1[i] - '0';
		} 
		else x = s_1[i];
	}
	for(int i = 0 ; i < s_2.size() ; i++){
		if(s_2[i] >= '0' && s_2[i] <= '9'){
			ans = ans*10 + s_2[i] - '0';
		}
		else y = s_2[i];
	}
	if(cnt == ans){
		cout << 1;
		if(x == 'A' && y == 'B' || y == 'C') cout << 1;
		else if(x == 'B' && y == 'A' || y == 'C') cout << 1;
		else if(x == 'C' && y == 'B' || y == 'A') cout << 1;
		else if(x == 'D' && y == 'F') cout << 1;
		else if(x == 'F' && y == 'D') cout << 1;
		else cout << 0;
	}
	else cout << 0 << 0;
	if(cnt == ans && x - y == 1) cout << 1;
	else cout << 0;
	return 0;
} 
