#include <bits/stdc++.h>
using namespace std;
long long n;
long long a;
char b;
string s,t;
long long sum = 0;
int vis[100005] = {};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a >> b;
		for(int i = 1;i <= a;i++){
			s += b;
		}
	}
	for(int i = s.size() - 1;i >= 0;i--){
		t += s[i]; 
	} 
	for(int i = 0;i < t.size();i++){
		if(t[i] != s[i]){
			vis[i] = 1;
		}
	}
	for(int i = 0;i <= t.size();i++){
		sum += vis[i];
	}
	cout << sum / 2;
}
