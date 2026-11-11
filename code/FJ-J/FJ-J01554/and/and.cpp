#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e5+10;
int n,m;
int a[N];
int b[N][35];
int bit[35]; 
int vis[N],tot,maxt,ans;
void to_two(int i){
	int x=a[i],t=0;
	while(x>0){
		if(x&1){
			b[i][t]=1;
			bit[t]++;
		} 
		x/=2;
		t++;
	}
	maxt=max(t,maxt);
	return ;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		to_two(i);
	}
	tot=n;
	for(int i=maxt;i>=0;--i){
		if(bit[i]<m) continue;
		for(int j=1;j<=n;++j){
			if(vis[j]) continue;
			if(b[j][i]==0){
				vis[j]=1;
				tot--;
				for(int k=i-1;k>=0;k--){
					if(b[j][k]) bit[k]--;
				}
			}
		}
	}
	ans=2147483647;
	for(int i=1;i<=n;++i)
		if(!vis[i]) ans&=a[i];
	cout<<ans;
	return 0;
}

