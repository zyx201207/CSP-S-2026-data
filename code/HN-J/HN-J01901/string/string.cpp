#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int s[5000005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	int t;
	int cnt=1;
	char c;
	int len=0;

	for(int i=1;i<=n;i++){
		cin>>t;
		cin>>c;
		len+=t;
		for(int j=1;j<=t;j++){
			s[cnt]=(int)c;
			cnt++;
		}
	}
	int l=len;
	len=(len+1)/2;
	int ans=0;
	for(int i=1;i<=len;i++){
		if(s[i]!=s[l-i+1]) ans++;
	}
	cout<<ans;
	return 0;
}

