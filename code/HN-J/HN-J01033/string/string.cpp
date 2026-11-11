#include<bits/stdc++.h>
#define int long long
using namespace std;
string s = "";
int a[200005];
int cheak(){
	int n = s.size(),ans = 0;
	for(int i = 0;i < n / 2;i ++){
		if(s[i] != s[n - i - 1])ans ++;
	}
	return ans;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.in","w",stdout);
	int n,cnt = 0;
	cin >>n;
	for(int i = 1;i <= n;i ++){
		char c;
		cin >>a[i] >>c;
		for(int j = 1;j <= a[i];j ++){
			s += c;
		}
	} 
	cout <<cheak();
	return 0;
}
