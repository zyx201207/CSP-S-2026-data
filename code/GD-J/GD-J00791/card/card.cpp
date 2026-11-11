#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
ll a[500005];
ll sum[300005];
string s[500005];
ll pos[300005];
ll ans[300005];
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int t=0;
	for(int i=n;i>=1;i--){
		t++;
		sum[a[i]]++;
		if(sum[a[i]]>1){
			s[t]=s[pos[a[i]]];
			pos[a[i]]=t;
		}
		else {
			s[t]=char(a[i]+'0')+s[t-1];
			pos[a[i]]=t;
		}
		for(int j=0;j<s[t].size();j++){
			ans[(s[t][j]-'0')]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	cout<<0;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int _=1;
//	cin>>_;
	while(_--){
		solve();
	}
	return 0;
}
