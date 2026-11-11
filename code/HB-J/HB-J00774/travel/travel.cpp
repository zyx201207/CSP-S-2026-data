#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("travel.in", "r", stdin); 
	freopen("travel.out", "w", stdout);
	string a, b;
	int block_a, block_b;
	
	cin >> block_a >> a >> block_b >> b;
	int num_a = stoi(a.substr(0, 2));
	int num_b = stoi(b.substr(0, 2));
	char alpha_a = a[2], alpha_b = b[2];
	// cout << "bdg: " << num_a << " " << num_b << "/" << alpha_a <<" " << alpha_b << endl;
	bool q1 = block_a == block_b;
	bool q2 = q1 && num_a == num_b;
	bool q3 = q2 && ('A' <= alpha_a <= 'C' && 'A' <= alpha_b <= 'C' 
			  || 'D' <= alpha_a <= 'F' && 'D' <= alpha_b <= 'F');
	bool q4 = q3 && abs(alpha_a - alpha_b) == 1;
	cout << q1 << q2 << q3 << q4;
	return 0;
}










































