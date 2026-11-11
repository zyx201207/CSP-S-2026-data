#include <iostream>
#include <vector>
using namespace std;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, ni;
	long long cnt = 0;
	char c;
	vector <char> s;
	
	cin >> n;

	
	for(int i = 1; i <= n; i++){
		cin >> ni >> c;
		while(ni--) s.push_back(c);	
	}
	
	for (int i = 0; i < s.size()/2; i++){
		if(s[i]!=s[n-i]) cnt++;
	}
	
	cout << cnt;
	return 0;
}