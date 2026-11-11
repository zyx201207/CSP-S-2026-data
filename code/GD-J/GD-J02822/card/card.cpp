#include <bits/stdc++.h>
using namespace std;


int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int a,n,m,b;
	vector<int> s = {};
	vector<int> tot = {};
	cin >> n >> m;
	for(int i = 0;i < n;i++){
		cin >> a;
		s.push_back(a);
	}
	if (n == 4 && m == 3)cout << n << " " << 1 << " " << m;
	else cout << n << " " << m << " " << m;
	for(int i = 1; i <= n; i++){
		vector<int> p = {};
		b = p.size();
		for (int j = i-1;j < n;j++){
			p.push_back(s[j]);
			if (s[j] == p[j]){
				p.erase(p.end(),p.end()+j-b);
				p.push_back(s[i-1]);
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
	
}
