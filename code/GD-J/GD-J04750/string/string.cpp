#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	string s1;
	long long cnt = 0;
	for(int i = 0;i < n;i++){
		long long x;
		char y;
		cin >> x >> y;
		for(int j = 0;j < x;j++){
			s1 += y;
			cnt++;
		}
	}
	cnt = 0;
	for(int i = 0;i < s1.size()/2;i++){
		if(s1[i] != s1[s1.size()-i-1]){
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}

