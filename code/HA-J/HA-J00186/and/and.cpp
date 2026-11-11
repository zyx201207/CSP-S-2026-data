#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int a[N],cnt[32],is1[N][32];
int s[N];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	int up=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=0;j<=31;j++){
			if(a[i]&(1ll<<j)){
				up=max(up,j);
				cnt[j]++;
				is1[i][j]=1;
			}
		}
	}
	int ans=0;
	int j=up;
	while(cnt[j]<m) j--;
	ans+=1ll<<j;
	for(int i=1;i<=n;i++){
		if(is1[i][j]) s[i]=1;
	}
	j--;
	for(;j>=0;j--){
		int cc=0;
		for(int i=1;i<=n;i++){
			if(is1[i][j]&&s[i]) cc++;
			else s[i]=0;
		}
		if(cc<m) continue;
		ans+=(1ll<<j);
	}
	cout<<ans;
	return 0;
}












