#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r", stdin);
	freopen("string.out", "w", stdout);
	string s = "";
	int n;
	cin >> n;
	while(n--){
		long long a;
		char b;
		cin>> a >> b;
		for(int i = 0; i<a; i++){
			s += b;
		}
	}//初始化s
	int l = s.length();
	long long sum = 0;
	string S ="";
	for(int i = l-1;i >= 0; i--) S += s[i];
	for(int i = 0; i < l; i++){
		if(s[i] != S[i])sum++;
	}
	cout << sum/2;
	//因在S和s比较中，非回文量sum注定为偶，则单改sum/2的值便可回文 
	return 0;
}
