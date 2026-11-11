#include <bits/stdc++.h>
using namespace std;
long long n;
long long a;
string b,s,f;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a>>b[i];
		for(int j=0;j<a;j++){
			s += b[i];
		}
	}
	int ans = 0;
	for(int i=s.size();i>=0;i--){
		f += s[i];
		if(f[i]==s[i]){
			ans = s.size()-i-1;
			break;
		}
	}
	cout << ans <<endl;
	
	return 0;
} 
