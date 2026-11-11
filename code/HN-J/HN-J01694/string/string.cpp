#include<bits/stdc++.h>
using namespace std; 
long long qwe;
char ans ;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	string s;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> qwe >> ans;
		for(int j=1;j<=qwe;j++){
			s += ans;
		}
	}
	long long mid = s.size()/2;
	long long log = s.size();
	long long sum = 0;
	for(int i=1;i<=mid;i++){
		if(s[i-1]!=s[log-i]){
			sum ++;
		}
	}
	cout << sum;
}
