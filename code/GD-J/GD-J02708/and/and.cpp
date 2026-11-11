#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,m,a[N],ans,cnt;
vector<int>G[64];
bool vis[N],flag;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=31;j>=0;j--){
			if((a[i]>>j)&1){
				G[j].push_back(i);
//				cout<<j<<' '<<i<<'\n';
			}
		}
	}
	for(int j=31;j>=0;j--){
		cnt=0;
		if(flag){
			for(int i:G[j])if(vis[i])cnt++;
		}
		else cnt=G[j].size();
//		cout<<cnt<<'\n';
		if(cnt>=m){
			ans+=1LL<<j;
			if(flag){
				for(int i=1;i<=n;i++)if(vis[i] && !((a[i]>>j)&1))vis[i]=0;
			}
			else for(int i:G[j])vis[i]=1;
			flag=1;
		}
	}
	cout<<ans;
	return 0;
}
