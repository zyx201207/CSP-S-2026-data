#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,ans=0,cnt=0;
	cin>>n;
	string s;
	for(int i=1;i<=n;i++){
		int x;
		char c;
		cin>>x>>c;
		cnt+=x;
		while(x--)s+=c;
	}
	for(int i=0;i<=cnt/2;i++){
		if(s[i]!=s[cnt-1-i])ans++;
	}
	cout<<ans;
	return 0;
}
