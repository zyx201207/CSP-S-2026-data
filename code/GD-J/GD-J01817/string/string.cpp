#include <bits/stdc++.h>
using namespace std;
int n;
string s="";
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++){
		int len;
		cin >> len;
		char ch;
		cin >> ch;
		for(long long j=1;j<=len;j++) s=s+ch;
	}
	n=(long long)s.size();
	if(n&1){
		long long i=n/2-1,j=n/2+1;
		while(i>=0 && j<n){
			if(s[i]!=s[j]) ans++;
			i--;j++;
		}
	}
	else{
		long long i=n/2-1,j=n/2;
		while(i>=0 && j<n){
			if(s[i]!=s[j]) ans++;
			i--;j++;
		}
	}
	cout << ans;
	return 0;
}
