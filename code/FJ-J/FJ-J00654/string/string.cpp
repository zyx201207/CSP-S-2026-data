#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
string s;
unsigned long long cnt;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	for(int i = 0;i<n;i++){
		int x;
		cin >> x;
		char c;
		cin >> c;
		for(int i = 0;i<x;i++){
			s+=c;
		}
	}
	for(int i = 0;i<s.length()/2;i++){
		if(s[i] != s[s.length()-1-i]){
			cnt++;
		}
	}
	cout << cnt;
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
