#include<bits/stdc++.h> 
using namespace std;
int n,m;
char ch;
string s;
int pd(){
	int ans = 0,l = s.size();
	for(int i = 0;i < l/2;i++){
		if(s[i]!=s[l-i-1]){
			ans++;
		}
	}return ans;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> m >> ch;
		while(m--) s+=ch;
	}
	cout << pd();
	return 0;
}
