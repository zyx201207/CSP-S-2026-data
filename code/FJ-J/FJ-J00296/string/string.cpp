#include<bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
int main(){
	int n;
	cin >> n;
	int maxn = 0;
	char b;
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> c[i];
		if(a[i] > maxn){
			maxn = a[i];
			b = c[i];
		}
	}
	string s1,s2;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= a[i]; j++){
			s1 += c[i];
		}
	}
	int len = s1.length();
	for(int i = 0; i * i < len; i++){
		if(s1[i] == b){
			s2[i] = b;
			s2[len - i - 1] = b;
		}
		else{
			s2[i] = s1[i];
		}
	}
	int cnt = 0;
	for(int i = 0; i < len; i++){
		if(s1[i] != s2[i]){
			cnt++; 
		}
	}
	cout << cnt;
    return 0;	
}
