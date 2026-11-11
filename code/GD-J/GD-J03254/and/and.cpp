#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
int n,m,ans;
int a[N],b[35],vis[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];vis[i]=1;
	}
	for(int j=29;j>=0;j--){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(vis[i]) cnt+=((a[i]>>j)&1);
		}
		if(cnt>=m){
			for(int i=1;i<=n;i++){
				if(vis[i]&&!((a[i]>>j)&1)) vis[i]=0;
			}
			ans+=(1<<j);
		}
	}
	cout<<ans;
	return 0;
}
