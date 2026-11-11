#include<bits/stdc++.h>
using namespace std;
int a[200005][2];
int b[201000][2];
long long d=0;
string s;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	for(int i = 1; i<= n; i++){
		int b;
		char c;
		cin >> b >> c;
//		a[i][0]=b;
//		a[i][1]=int(c);
//		d+=b;
		
		if (b>10000000){ // ·À±¬ 
			cout << "TLE";
			return 0;
		}
		
		for(int j=1; j<=b; j++) s+=c;
	}
	long long res = 0;
	string s2 = s;
	reverse(s2.begin(), s2.end());
	for(int i = 0; i<s.size()/2; i++){
		if(s[i]!=s2[i]) res++;
	}
	
	cout << res;
	
	return 0;
}
