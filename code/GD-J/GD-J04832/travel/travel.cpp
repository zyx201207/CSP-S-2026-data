#include<bits/stdc++.h>
#define ll long long
#define N 1

using namespace std;
char a_1[10], a_2[10];
char b_1[10], b_2[10];
int q, w;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out","w",stdout);
	for(int i = 1; i <= 2; ++i) cin >> a_1[i];
	for(int i = 1; i <= 3; ++i) cin >> a_2[i];
	for(int i = 1; i <= 2; ++i){
		cin >> b_1[i];
		if(a_1[i] != b_1[i]){
			cout << "0000";
			return 0;
		}
	}
	cout << 1;
	for(int i = 1; i <= 2; ++i){
		cin >> b_2[i];
		if(a_2[i] != b_2[i]){
			cout << "000";
			return 0;
		}
	}
	cout << 1;
	cin >> b_2[3];
	if(a_2[3] == 'D' || a_2[3] == 'F') q = 1;
	if(b_2[3] == 'D' || b_2[3] == 'F') w = 1;
	if(q != w){
		cout << "00";
		return 0;
	}
	cout << 1;
	if(a_2[3] == 'A' && b_2[3] == 'C') cout << 0;
	else if(a_2[3] == 'C' && b_2[3] == 'A') cout << 0;
	else cout << 1;
	return 0;
}
