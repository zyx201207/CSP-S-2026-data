#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200010],s[32],b[200010][32],ans;
bool vis[200010];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int cnt=0;
		while(a[i]){
			b[i][cnt++]=a[i]%2;
			a[i]/=2;
		}
	}
	for(int j=31;j>=0;j--){
		int c=0;
		for(int i=1;i<=n;i++){
			if(b[i][j]==1&&!vis[i])c++;
		}
		if(c>=m){
			ans+=(1<<j);
			for(int i=1;i<=n;i++)if(b[i][j]==0)vis[i]=1;
		}
	}
	cout<<ans;
	return 0;
}

