#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,sum = 0,ans = 0;
	cin>>n;
	string s;
	for (int i = 0; i < n; i++){
		int a;
		string c;
		cin>>a>>c;
		for (int j = 0; j < a; j++){
			s += c;
		}
		sum += a;
	}
	string l = s.substr(0, sum / 2 + sum % 2);
	string r = s.substr(sum / 2 + sum % 2, s.size());
	for (int i = 0; i < sum / 2; i++){
		if (l.substr(i, 1) != r.substr(i, 1))
			ans++;
	}
	cout<<ans;
	return 0;
}
