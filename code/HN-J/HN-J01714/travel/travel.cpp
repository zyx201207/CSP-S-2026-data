#include <bits/stdc++.h>
using namespace std;

string sit1, sit2, t1, t2;
int vis[10] = {1e8, 1, 1, 1, 0, 1e8, 0};

int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> t1 >> sit1 >> t2 >> sit2;
	if(t1 == t2){
		cout << "1";
	} else {
		cout << "0000";
		return 0;
	}
	if(sit1[0] == sit2[0] && sit1[1] == sit2[1]){
		cout << "1";
	} else {
		cout << "0";
	}
	if(sit1[0] == sit2[0] && sit1[1] == sit2[1] && vis[sit1[2] - 'A' + 1] == vis[sit2[2] - 'A' + 1]){
		cout << "1";
	} else {
		cout << "0";
	}
	if(sit1[0] == sit2[0] && sit1[1] == sit2[1] && (sit1[2] == char(sit2[2] + 1) || sit1[2] == char(sit2[2] - 1)) && (vis[sit1[2] - 'A' + 1] == vis[sit2[2] - 'A' + 1])){
		cout << "1";
	} else {
		cout << "0";
	}
	return 0;
} 

/*
 
*/
