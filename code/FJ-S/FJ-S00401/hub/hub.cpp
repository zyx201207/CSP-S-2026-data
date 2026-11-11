#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n,k,b[600001],c;
vector<int>e[600001];
int dfs(int x,int fa){
	if(b[x]==1)return 0;
	int res = 1e9;
	for(int v:e[x]){
		if(v==fa)continue;
		res = min(res,dfs(v,x)+1);
	}
	return res;
}
bool check(int d){
	int lst = d,cnt = 1;
	for(int i = d+1;i<=n/2;i++){
		if((i-(i+lst)/2)>=d){
			lst = i;
			cnt++;
		}
	}
	return cnt<=k;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int T;
	cin>>c>>T;
//	cout<<c<<endl;
	while(T--){
		cin>>n>>k;
		for(int i = 1;i<=n;i++)e[i].clear();
		for(int i = 1;i<n;i++){
			int u,v;
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		if(n==k){
			cout<<0<<endl;
			continue;
		}
//		cout<<c<<endl;
		if(c<=3){
			int ans = 1e9;
			for(int i = 1;i<(1<<n);i++){
				int cnt = 0;
				for(int j = 1;j<=n;j++){
					if(i&(1<<(j-1))){
						cnt++;
						b[j] = 1;
					}else b[j] = 0;
				}
				if(cnt!=k)continue;
				cnt = 0;
				int dans = 0;
				for(int j = 1;j<=n;j++){
					for(int v:e[j]){
						if(b[j] and b[v])cnt++;
					}
				}
				if(cnt!=2*k-4)continue;
//				for(int j = 1;j<=n;j++){
//					cout<<b[j]<<" ";
//				}
//				cout<<endl;
				for(int j = 1;j<=n;j++){
					dans = max(dans,dfs(j,-1));
				}
				ans = min(ans,dans);
			}
			cout<<ans<<endl;
			continue;
		}else if(c==13 or c==14){
			k/=2;
			int mid = ((n/2+1)/2+1)/2;
			int mid2 = n/2+1-mid;
			int lans1 = mid,rans1 = n/2-mid2+1;
			int lans2 = n/2+1-mid+1,t = ((n/2+1)%2==mid%2);
			for(int i = 1;i<=k;i++){
				int ma = max(max(lans1,rans1),lans2);
				if(lans1==ma)lans1--;
				else if(lans2==ma){
					if(t==1){
						lans2--;
						t = 0;
					}else t = 1;
				}
				else{
					rans1--;
				}
			}
			cout<<max(max(lans1,rans1),lans2)<<endl;
			continue;
		}
	}
	return 0;
}
