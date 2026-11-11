#include <iostream>
#include <vector>
using namespace std;
using numtype = long long;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	numtype n;
	cin >> n;
	
	if (n == 1) cout << "0";
	
	vector<numtype> len(n, 0);
	vector<char> chars(n, 0);
	
	for (numtype i = 0; i < n; ++i) cin >> len[i] >> chars[i];
	
	//numtype sum = 0;
	//for (numtype i = 0; i < n; ++i) sum += len[i];
	
	numtype l_id = 0;
	numtype r_id = n - 1;
	
	numtype total = 0;
	while (l_id < r_id){
		if (len[l_id] <= len[r_id]){
			if (chars[l_id] != chars[r_id]){
				total += len[l_id];
			}
			
			len[r_id] -= len[l_id];
			++l_id;
		}
		else{
			if (chars[l_id] != chars[r_id]){
				total += len[r_id];
			}
			
			len[l_id] -= len[r_id];
			--r_id;
		}
		
	}
	
	cout << total;
	
	return 0;
}
