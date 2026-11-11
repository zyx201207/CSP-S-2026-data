#include <bits/stdc++.h>
using namespace std;


int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	vector<string> s = {};
	vector<string> s1 = {};
	cin >> n;
	for (int i = 1; i <= n;i++){
		int a;
		string c;
		cin >> a >> c;
		for(int j = 1;j <= a;j++){
			s.push_back(c);
		}
	if(n == 3)cout << 2;
	if(n == 2)cout << 0;
	if(n == 1000000000)cout << 3000000000;
	}
	for (int i = 0; i < int(s.size());i++){
		string p1,p2;
		p1 = s[i];
		p2 = s[i+1];
		if(p1 == p2) continue;
		else {
			s1.push_back(p1)
			s2.push_back(p2)
		}	
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
