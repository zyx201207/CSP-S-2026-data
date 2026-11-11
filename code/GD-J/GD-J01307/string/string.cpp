#include<bits/stdc++.h>
using namespace std;
#define int long long
struct kuai{
	int l,r;
	char c;
}a[1000005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,ans=0,hui=0;
	string s;
	cin>>n;
	char c;
	for(int i=1,tmp;i<=n;i++){
		cin>>tmp>>c;
		for(int j=1;j<=tmp;j++) s+=c;
	}
	for(int i=0;i<s.length()/2;i++){
		if(s[i]!=s[s.length()-i-1]) ans++;
	}
	cout<<ans;
	return 0;
}

