#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[1000005],t[35],ans;
bool vis[1000005];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=0;j<=29;j++){
			if(a[i]&(1<<j)) t[j]++;
		}
	}
	for(int i=29;i>=0;i--){
		if(t[i]<m) continue;
		ans+=(1<<i);
		for(int j=1;j<=n;j++){
			if((!(a[j]&(1<<i)))&&!vis[j]){
				vis[j]=1;
				for(int k=0;k<=29;k++) if(a[j]&(1<<k)) t[k]--;
			}
		}
	}
	cout<<ans;
	return 0;
}

