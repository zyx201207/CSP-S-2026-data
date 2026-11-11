#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,len = 0,ans = 0;
	cin>>n;
	string str = "";
	while(n--){
		int a;
		char s;
		cin>>a>>s;
		len += a;
		while(a--) str += s;
	} 
	for(int i = 0,j = len - 1;i <= len / 2;i++,j--){
		if(str[i] != str[j]) ans++;
		if(i + 1 == j) break;
	}
	cout<<ans;
	return 0;
}
