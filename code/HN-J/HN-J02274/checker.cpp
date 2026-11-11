#include <bits/stdc++.h>
using namespace std;
int main() {
	vector<string> names = {"travel", "string", "and", "card"};
	vector<int> tcnt = {5, 6, 5, 6};
	
	int n = names.size();
	
	vector<string> wa;
	
	for(int i = 0; i < n; i ++) {
		string s = names[i] + "\\" + names[i];
		int m = tcnt[i];
		s.push_back('0');
		for(int j = 0; j < m; j ++) {
			s.back() ++;
			int result = system(("fc " + s + ".out " + s + ".ans").c_str());
			if(result) wa.push_back(s.substr(names[i].size() + 1, s.size()));
		}
	}
	
	if(wa.empty()) cout << "OK all samples passed." << endl;
	else{
		cout << "Wrong answer on " << wa.size() << " sample(s):" << endl;
		for(auto s : wa) cout << s << "\n";
	}
} 
/*
I've been counting down the days, and the nights

Since you last said that you love me

And it's cold here in the shadow, with no lights

Since you last said that you love me

Time is like an enemy leaving lovers by the side

The more you cling to love the more you gonna lose your mind

All I feel is sadness now

Taking over, taking over, taking over

All I see is black clouds above

Taking over, taking over, taking over
*/ 
