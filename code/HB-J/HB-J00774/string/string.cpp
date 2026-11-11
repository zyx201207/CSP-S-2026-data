#include <bits/stdc++.h>
using namespace std;


int main2() {
	
}

int main() {
	freopen("string.in", "r", stdin); 
	//freopen("string.out", "w", stdout);
	int n, ans = 0;
	 cin >> n;
	pair<int, char> input[200005];
	int len = 0, len1 = 0;
	// hack
	int all_1 = true, all_same_letter = true, _ch = '\0', half_and_half = true, _cnt_s = 0, _cnt_e = 0, _lett_s = '\0', _lett_e = '\0', _cnt_mode=0 ;
	for (int i = 0; i < n; i++) {
		 cin >> input[i].first >> input[i].second;
		 len += input[i].first;
		 if (input[i].first != 1) all_1 = false;
		 if (_ch == '\0') {
			 _ch = input[i].second;
		 }
		 else if (_ch != input[i].second) {
			 all_same_letter = false;
		 }
	}
	int mid = len /2;
	if (all_1) {
		for (int i = 0; i < mid; i++) {
			ans += input[i].second != input[n - i - 1].second;
		}
		cout << ans;
		return 0;
	}else if(all_same_letter) {
		cout << 0;
		return 0;
	}
	for (int i = 0; i < n; i++){
		
		 if (_lett_s == '\0') {
			 _lett_s = input[i].second;
			 _cnt_s++;
		 }
		 if (_cnt_mode == 0 && _lett_s == input[i].second) {
			 _cnt_s++;
		 }if (_cnt_mode == 1 && _cnt_e == 0) {
			 _lett_e = input[i].second;
			 _cnt_e++;
		 }
		 if (_cnt_mode == 1 && _lett_e && _lett_e == input[i].second && _cnt_e != 0) {
			 _cnt_e++;
		 }
		 if (_cnt_mode == 1 && _lett_e && _lett_e == input[i].second) {
			 half_and_half = false;
			 break;
		 }
		 if (_lett_s != input[i].second) {
			 if (_cnt_s == mid) {
				 _cnt_mode = 1;
			 }
		 }
	}
	if (half_and_half && n % 2 == 0) {
		cout << mid;
		return 0;
	}
	// hack_end
	int mid_i = -1, mid_seg_i = -1;
	for (int i = 0; i < n; i++) {
		len1 += input[i].first;
		mid_i = i;
		if (len1 > mid) {
			mid_seg_i = len1 - mid - 1;
			break;
		}
		cout << "dbg: " << len1 << ' ' << mid_i << endl;
	}
	cout << "dbgd: " << mid << ' ' << len1 << ' ' << mid_i << ' ' << mid_seg_i << endl;
	
	return 0;
}
