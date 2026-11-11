#include<bits/stdc++.h>
#define ll long long
using namespace std;

int c1, c2, l1, l2, cnt1, cnt2;

char s1, s2;

int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> l1 >> s1 >> c2 >> l2 >> s2;
	if(c1 == c2){
		cout << 1;
	}else{
		cout << "0000";
		return 0;
	}
	if(l1 == l2){
		cout << 1;
	}else{
		cout << "000";
		return 0;
	}
	if(((s1 == 'A' || s1 == 'B' || s1 == 'C') && (s2 == 'A' || s2 == 'B' || s2 == 'C')) || ((s1 == 'D' || s1 == 'F') && (s2 == 'D' || s2 == 'F'))){
		cout << 1;
	}else{
		cout << "00";
		return 0;
	}
	cnt1 = s1 - 'A';
	cnt2 = s2 - 'A';
	if(((s1 == 'D' || s1 == 'F') && (s2 == 'D' || s2 == 'F')) || (cnt1 - cnt2 == 1 || cnt2 - cnt1 == 1)){
		cout << 1;
	}else{
		cout << 0;
	}
	return 0;
} 
