#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 101;
int n,a[N],t,ans;
string s,s2;
char c[N];
int main(){
	freopen("string3.in","r",stdin);
	freopen("string3.out","w",stdout);
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i] >> c[i];
		for(int j=0;j<a[i];j++)
			s += c[i];
	}
	int len = s.size();
	for(int i=0;i<len;i++)
		if(s[len-1-i] != s[i])
			t=1;
	if(t!=1){
		cout << 0;
		return 0;
	}
	if(len%2==0){
		for(int i=0;i<len/2;i++)
			s2 += s[i];
		for(int i=len/2-1;i>=0;i--)
			s2 += s[i];
		for(int i=0;i<len;i++){
			if(s2[i]!=s[i]) ans++;
		}
	}
	else{
		for(int i=0;i<len/2;i++)
			s2 += s[i];
		for(int i=len/2;i>=0;i--)
			s2 += s[i];
		for(int i=0;i<len;i++){
			if(s2[i]!=s[i]) ans++;
		}
	}
	cout << ans;
	return 0;
}
