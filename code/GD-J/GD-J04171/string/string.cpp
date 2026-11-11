#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	long long cnt = 0, sum = 0;
	vector<string> v;
	vector<string> v1;
	vector<string> v2;
	vector<string> v3;
	for(int i = 1;i <= n;i++){
		long long x;
		string s;
		cin >> x >> s;
		for(int i = 1;i <= x;i++){
			v.push_back(s);
			v1.push_back(s);
			v3.push_back(s);
		} 
	}
	for(int i = v.size()-1;i >= 0;i--){
		v2.push_back(v1[i]);
		v1.pop_back();
	}
	sum = ceil(v3.size() / 2);
	while(sum--){
		if(v.front() != v2.front()){
			cnt++;
		}
		v.pop_back();
		v2.pop_back();
	}
	cout << cnt;
	return 0;
}
