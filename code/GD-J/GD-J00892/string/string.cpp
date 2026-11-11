#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
int n,sum=0,ans=0,a[maxn],l[maxn],r[maxn];
char c[maxn];
string s;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s=s+c[i];
		}
	}
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-i-1]) ans++;
	}
	cout<<ans;
	return 0;
} 
