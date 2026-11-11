#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	bool f=true;
	int n,a[200005],su=0;
	char c[200005];
	string s="";
	cin >> n;
	for (int i=1;i<=n;i++){
		cin >> a[i] >> c[i];
		for (int j=1;j<=a[i];j++) s+=c[i];
	}

	for (int i=1;i<=s.size()/2;i++){
		if (s[i]!=s[s.size()-i+1]) su++;
	}
	cout << su;
	return 0;
}
