# include <bits/stdc++.h>
using namespace std;

int ans[4];
string tc1, tc2, ts1, ts2;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> tc1 >> tc2 >> ts1 >> ts2;
	
	if 
	(tc1 == ts1){
	ans[0] = 1;
	
	if 
	(tc2[0] == ts2[0] && tc2[1] == ts2[1]){
	ans[1] = 1;
	
	if 
	(((tc2[2] == 'A' || tc2[2] == 'B' || tc2[2] == 'C') && 
	(ts2[2] == 'A' || ts2[2] == 'B' || ts2[2] == 'C')) || 
	((tc2[2] == 'D' || tc2[2] == 'F') && 
	(ts2[2] == 'D' || ts2[2] == 'F'))){
	ans[2] = 1;
	
	if 
	((tc2[2] == 'A' && ts2[2] == 'B') || 
	(tc2[2] == 'B' && ts2[2] == 'C') || 
	(tc2[2] == 'D' && ts2[2] == 'F')){
	ans[3] = 1;
	}}}}
	
	for (int i = 0; i < 4; ++i){
		cout << ans[i];
	}
	return 0;
}
