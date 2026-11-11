#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e5+5;
int l[N];
char c[N];

signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,ans=0;cin>>n;
	string s;
	for(int i=1,a;i<=n;i++){
		char c;
		cin>>a>>c;
		while(a){
			a--;
			s+=c;
		}
	}
	for(int i=0;i<=s.size()/2;i++){
		if(s[i]!=s[s.size()-i-1]) ans++;
	}
	cout<<ans<<'\n';
	return 0;
} 
