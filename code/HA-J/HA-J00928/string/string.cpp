#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n;
string s;
int as=0;
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		as+=x;
		char c;
		cin>>c;
		for(int j=1;j<=x;j++){
			s+=c;
		}
	}
	int len=(as+1)/2;
	int l=as/2;
	if(n%2==1) l+=1;
	int ans=0;
	for(int i=1,j=l;i<=len;i++,j--){
		if(s[i]!=s[j]){
			ans++;
		}
	}
	cout<<ans;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}

