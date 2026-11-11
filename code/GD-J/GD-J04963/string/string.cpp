#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	int n,shu;
	cin >> n;
	char x;
	for (int i=1;i<=n;i++){
		cin >> shu;
		cin >> x;
		s+=shu*x;
	}
	string s1;
	long long int sum=0;
	for (long long int i=s.size();i>0;i--){
		for (long long int j=0;j<s.size();i++){
			s1[j]==s[i];
		}
	}
	for (long long int i=1;i<=s.size();i++){
		if (s1[i-1]!=s[i+1]){
			sum++;
		}
	}
	cout << sum-1;
	return 0;
}
