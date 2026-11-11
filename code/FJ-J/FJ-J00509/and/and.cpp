#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005],ans,b[200005][31];
bool flag[200005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) flag[i]=1;
	for(int i=1;i<=n;i++){
		int pos=0;
		while(a[i]) b[i][++pos]=a[i]%2,a[i]/=2;
	}for(int i=30;i>=1;i--){
		int sum=0;
		for(int j=1;j<=n;j++) if(flag[j]) sum+=b[j][i];
		if(sum>=m){
			for(int j=1;j<=n;j++) if(b[j][i]==0) flag[j]=0;
			ans+=(1<<(i-1));
		}
	}cout<<ans;
	return 0;
}
