#include<bits/stdc++.h>
using namespace std;
const int MAXN = 10005;
long long c,n,m,d,q,ans;
long long x,y;		
long long finaltime;
long long getouttime[MAXN],where[505],leavesubtime[505][MAXN],line[505];
bool flag[MAXN];
long long dfs(long long id,long long sum){
	if(id==y){
		ans = max(ans,sum);
		return ans;
	}
	for(int i=1;i<=n;i++){
		if(where[i]==id){
			sum+=leavesubtime[i][id];
			for(int j=1;j<=line[i];j++){
				if(flag[where[j]]){
					flag[j]=true;
					dfs(where[j],sum+leavesubtime[i][id]+leavesubtime[i][where[j]]);
					flag[j]=false;
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++){
		cin >> getouttime[i];
	}
	for(int i=1;i<=n;i++){
		int k;cin >> k;
		for(int j=1;j<=k;j++){
			cin >> where[i] >> leavesubtime[j][i];
		}
		line[i]=k;
	}
	while(q--){
		cin >> x >> y;
		memset(flag,false,sizeof flag);
		flag[x]=true;
		finaltime = getouttime[x]+getouttime[y]+dfs(x,0);
		cout << finaltime+10 << "\n";
	}
	return 0;
}
