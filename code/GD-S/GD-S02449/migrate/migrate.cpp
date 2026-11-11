#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[2000001],t[2000001],dp[5001][5001];
void solve(){
	int n,d;
	cin>>n>>d;
	bool f=0,bj[2000001]; 
	memset(bj,0,sizeof bj);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i!=1){
			t[i]=a[i]-a[i-1];
			if(i!=2){
				if(t[i]!=t[i-1]) f=1;
			}
		}
		bj[a[i]]++;
	}
	if(!f){
		if(d<=t[2]) cout<<0<<"\n";
		else cout<<n-d*2+1<<"\n";
	}
	//那个啥，我不做了 
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T=1;
	cin>>T>>T;
	while(T--) solve();
	return 0;
}
