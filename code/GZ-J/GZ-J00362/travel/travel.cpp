//GZ-J00362 华东附校 蒋一辰 
#include<bits/stdc++.h>
using namespace std;

string cr, sr, cx, sx; 

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> cr >> sr >> cx >> sx;
	if(cr == cx) cout << 1;
	else cout << 0;
	if(sr[0] == sx[0] && sr[1] == sr[1]) cout << 1;
	else cout << 0;
	if(sr[0] == sx[0] && sr[1] == sr[1] && (sr[2] <=  'C' && sx[2] <= 'C' || sr[2] >  'C' && sx[2] > 'C')) cout << 1;
	else cout << 0;
	if(sr[0] == sx[0] && sr[1] == sr[1] && ((sr[2] <=  'C'  && sr[2] > sx[2] && sr[2] - sx[2] == 1 || sx[2] <=  'C'  && sx[2] > sr[2] && sx[2] - sr[2] == 1) || sr[2] >  'C' && sx[2] > 'C')) cout << 1;
	else cout << 0;
	return 0;
}
