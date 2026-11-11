#include <bits/stdc++.h> 
using namespace std;

int main(){
	freopen ("string.in","r",stdin);
	freopen ("string.out","w",stdout);
	int n;
	cin >> n;
	string s;
	for (int i=0;i<n;i++){
		int cnt;
		cin >> cnt;
		char a;
		cin >> a;
		for (int j=0;j<cnt;j++){
			string s = s+a;
		}		
	}
	int len= s.length();
	int res =0;
	for (int i=len;i>0;i--){
		int sum= 0;
		if (s[i]!=s[sum]){
			res++;
		}
		sum++;
	}
	cout << res;
	return 0;
}
