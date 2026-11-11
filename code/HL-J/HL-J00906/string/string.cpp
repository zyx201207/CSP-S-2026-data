#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n;
long long a[N];
bool vis[N];
char c[N];
string s = "";
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin>>n;
	for(int i = 1; i <= n; i++){
		cin>>a[i]>>c[i];
		while(a[i]--){
			s += c[i]; 
		}
	}

	int l = 0, r = s.size()-1;
	int ans = 0;
	while(l < r){
		if(s[l] != s[r]){
			ans++;
		}
		l++;
		r--;
	}
	cout<<ans;
	return 0;
}