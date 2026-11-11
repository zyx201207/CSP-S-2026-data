#include<bits/stdc++.h>
using namespace std;;
int a[200005];
char c[200005];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); 
	int n,ans = 0;
	int len = 0;
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i] >> c[i];
		len+=a[i];
		s.append(a[i],c[i]);
	}
	//cout << s;
	for(int i = 0;i < len/2;i++){
		if(s[i]!=s[n-i]){
			ans++;
		}
	}
	cout << ans;
	return 0;
}
