#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[100010];char c[100010];
string s;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	int L=1;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			s[L]=c[i];
			L++;
		}
	}
	int ans=0;
	for(int i=1;i<=s.size()/2;i++){
		if(s[i]!=s[L+1-i]){
			ans++;
		}else{
			continue;
		}
	}
	cout<<ans;
	return 0;
}
