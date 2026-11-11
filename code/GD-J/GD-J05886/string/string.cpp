#include <bits/stdc++.h>
using namespace std;
long long n;
string s;
long long len,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cin>>n;
	for (long long i = 1,x;i<=n;i++){
		char c;
		cin>>x>>c;
		for (long long j = 1;j<=x;j++)s+=c;
	}len = s.length();
	for (int i = 0;i<len/2;i++){
		if (s[i]!=s[len-1-i]){
			ans++;
			s[len-1-i] = s[i];
		}
	}
	cout<<ans;
	return 0;
}
