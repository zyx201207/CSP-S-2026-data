#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,ans;string s;
	cin>>n;
	for(int i=1; i<=n; i++){
		int x;string a;
		cin>>x>>a;
		while(x){
			if(x&1) s+=a;
			a+=a;
			x>>=1;
		}
	}
	int l=s.size();
	for(int i=0; i<l/2; i++){
		if(s[i]!=s[l-i-1]) ans++;
	}
	cout<<ans;
	return 0;
}
