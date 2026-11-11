#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,ans,len;
string s;
signed main(){	
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		string s1;
		int a;cin>>a>>s1;
		len+=a;
		for(int j=1;j<=a;j++){
			s=s+s1;
		}
	}
	for(int i=0,j=len-1;i<=j;i++,j--){
		if(s[i]!=s[j])ans++;
	}
	cout<<ans;
	return 0;
}
