#include<bits/stdc++.h>
using namespace std;
vector<char> s;
int ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	while(n--){
		int x;
		char y;
		cin >> x >> y;
		for(int i = 1; i <= x; i++){
			s.push_back(y);
		}
	} 
	n = s.size();
	for(int i = 0; i < n / 2; i++){
		if(s[i] != s[n - i -1]){
			ans++;
		}
	}
	cout << ans;
	return 0;
}
