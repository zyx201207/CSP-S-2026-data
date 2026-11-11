#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,M=31;
int n,m,c[M],a[N],ans;
bool vis[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=0;j<M;j++){
			if(a[i]&(1<<j)) c[j]++;
		}
	}
	for(int i=M-1;i>=0;i--){
		if(c[i]>=m){
			ans+=(1<<i);
			for(int j=1;j<=n;j++){
				if(vis[j]) continue;
				if(a[j]&(1<<i)) continue;
				vis[j]=true;
				for(int k=0;k<M;k++){
					if(a[j]&(1<<k)) c[k]--;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
