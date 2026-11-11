#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,ans;
string s,ac;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	
	for (int i=1;i<=n;i++){
		int a;
		char b;
		cin>>a>>b;
		for (int j=1;j<=a;j++){
			ac+=b;
		}
	}
	
	int len=ac.size()-1;
	for (int i=0;i<=len/2;i++){
		if (ac[i]!=ac[len-i]) ans++;
	}
	cout<<ans;
	return 0;
}
