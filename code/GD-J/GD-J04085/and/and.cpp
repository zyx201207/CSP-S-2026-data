#include<bits/stdc++.h>
using namespace std;
using i64=long long;
using u64=unsigned long long;
using u32=unsigned;
const int N=2e5+5;
int n,m,ans,a[N],vis[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int b=29;b>=0;--b){
		int cnt=0;
		for(int i=1;i<=n;++i){
			if(vis[i])continue;
			if(a[i]>>b&1)++cnt;
		}
		if(cnt>=m){
			for(int i=1;i<=n;++i){
				if(~a[i]>>b&1){
					vis[i]=1;
				}
			}
			ans|=1<<b;
		}
	}
	cout<<ans;
}