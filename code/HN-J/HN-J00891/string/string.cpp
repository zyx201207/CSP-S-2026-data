#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,x,len=0,ans=0;
char c;
int mp[100002505];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>c;
		for(int j=1;j<=x;j++)
			mp[++len]=c;
	}
	for(int i=1;i<=len/2;i++){
		if(mp[i]!=mp[len-i+1]) ans++;
	}
	cout<<ans;
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
