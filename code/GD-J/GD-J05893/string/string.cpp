#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e7+10;
int n,ai,l=0,ans=0;
char ci;
char s[maxn];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> ai >> ci;
		for(int j = 1;j <= ai;j++){
			l++;
			s[l] = ci;
		}
	}
	
	for(int i = 1;i <= l/2+1;i++){
		if(s[i]!=s[l+1-i])ans++;
	}
	cout << ans;
	/*
	for(int i = 1;i <= l+1;i++){
		cout << s[i];
	}
	*/
	
	return 0;
} 
