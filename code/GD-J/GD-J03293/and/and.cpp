#include <bits/stdc++.h>
using namespace std;

int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	int a[100005];
	string b[200005] = {""};
	int n,m;
	string s;
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++){
		int num = a[i];
		s = "";
		while(num > 0){
			s += char(num%2);
			num/=2;
		}
		for(int i = s.length();i >= 1;i++){
			b[s.length()-i+1]+=s[i];
		}
	}
	cout << b[1];
	return 0;
} 
