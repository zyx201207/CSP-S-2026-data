#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	long long n;
	cin >> n;
	for(int i=1;i<=n;i++){
		string x;
		long long t;
		cin >> t >> x;
		for(int j=1;j<=t;j++){
			s+=x;
		}
	}
	long long cnt=0;
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-1-i]){
			cnt++;
		}
	}
	cout << cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

