#include<bits/stdc++.h>
using namespace std;
string s="";
int n,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n;
	for (int i=1;i <= n;i++){
		int a=0;
		char c='a';
		cin >> a >> c;
		for (int j = 1;j <= a;j++){
			s+=c;
		}
	}
	int l=0,r=s.size()-1;
	while(l<=r){
		if (s[l]!=s[r]){
			ans++;
		}
		l++;
		r--;
	}
	cout << ans;
	return 0;
}

