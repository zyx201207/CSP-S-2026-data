#include <bits/stdc++.h>
using namespace std;

long long n;
string s,s2;

int main(){
	freopen("string.in",r,stdin);
	freopen("string.out",w,stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;
	while(n--){
		long long x;char ss;
		cin >> x >> ss;
		for(int i=1;i<=x;i++){
			s+=ss;
		}
	}
	int len = s.size();
	int len_two=s.size();
	for(int i=0;i<len;i++){
		s2[i] = s[len_two-i-1];
	}
	long long ans=0;
	for(int i=0;i<len;i++){
		if(s[i]!=s2[i])ans++;
	}
	cout << ans;
	return 0;
}
