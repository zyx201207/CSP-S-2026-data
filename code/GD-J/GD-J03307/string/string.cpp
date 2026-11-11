#include<bits/stdc++.h>
using namespace std;
int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s = "";
	long long n,max = 0,t = 0;
	char x;
	cin >> n;
	long long a[n];
	for(int i = 0;i < n;i++){
		cin >> a[i] >> x;
		max += a[i];
		for(int j = 0;j < a[i];j++){
			s = s + x;
		}
	}
	for(int i = 0;i < (s.size()+1)/2;i++){
		if(s[i] != s[max-i-1]){
			t++;
		}
	}
	cout << t;
	
	return 0;
}
