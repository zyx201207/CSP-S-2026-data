#include <bits/stdc++.h> 
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n,all=0,cn=0;
	long long a[10000];
	string s[10000];
	string full = "";
	cin >> n;
	for(int i = 0;i <= n-1;i++){
		cin >> a[i];
		cin >> s[i];
	}
	for(int i = 0;i <= n-1;i++){
		all += a[i];
		for(int j = 1;j <= a[i];j++){
			full = full + s[i];
		}		
	}
	for(int k = 0;k <= n-1;k++){
		if(all%2 != 0&&k == (all-1)/2) break;
		if(full[k] != full[all-1-k]){
			cn++;
			full[all-k] = full[k];
		}
		
	}
	cout << cn;
	return 0;
} 
