#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n;
string s;
int cnt,ans;;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int t;
		char c;
		cin>>t>>c;
		for(int i=1;i<=t;i++){
			s+=c;
			cnt++;
		} 
	}
	cnt--;
	for(int i=0;i<=cnt/2;i++){
		if(s[i]!=s[cnt-i]) ans++;
	}
	cout<<ans;
	return 0;
}
/*
2
2 a
3 a
3
2 a
2 b
1 c
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
