#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e5+10;
int n,m;
int a[maxn];
int vis[maxn];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		vis[i]=1;
	}
	int ans=0;
	for(int i=30;i>=0;i--){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if((a[j]>>i)&1){
				cnt++;
				if(!vis[j]){
					cnt--;
				}
			}
		}
		if(cnt>=m){
			ans+=(1<<i);
			for(int j=1;j<=n;j++){
				if(((a[j]>>i)&1)==0){
					vis[j]=0;
				}
			}
		}
	} 
	cout<<ans;
	return 0;
}

