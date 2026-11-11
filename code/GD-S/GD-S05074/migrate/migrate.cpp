#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e6+10;
long long t,n,d,iland[maxn];
bool ilandif[maxn];
long long c,ans,yl,wt,ret,mi=100000009;
long long rp = 100000009;

//iland[v]v座岛的坐标，ilandif【v】v坐标是否有岛 
// long long !!!!!

long long dfs(long long x,long long y){
	//dfs寻找从x岛到y岛最短路径长度。
	if(abs(iland[y]-iland[x])<=d){
		return 1;
	}
	else{
		for(long long i = iland[x]+d;i>iland[x];i--){
			if(ilandif[i+mi+1]){
				wt = dfs(i,y)+1;
				break;
			}
		}
		return wt;
	}
}

long long findroad(long long x,long long y){
	ret = 1;
	if(abs(iland[y]-iland[x])<=d){
		return 1; 
	}
	else{
		rp=100000009;
		for(long long i = iland[x]+d;i>iland[x];i--){
			yl = dfs(i,y)+1;
			if(ilandif[i+mi+1]){
				if(rp==yl){
					ret++;
				}
				else if(rp > yl){
					rp = yl;
					ret = 1;
				}
			}
		}
		return ret;
	}
}


int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		ans = 0;
		cin >> n >> d;
		memset(iland,0,sizeof(iland));
		for(long long i = 1;i <= n;i++){
			cin >> iland[i];
			mi = min(mi,iland[i]);
		}
		mi = abs(mi);
		for(long long i = 1;i <= n;i++){
			iland[i]+=abs(mi)+1;
		}
		for(long long i = 1;i <= n;i++){
			ilandif[iland[i]] = 1;
		}
		for(long long i = 1;i < n;i++){
			for(long long j = i;j<=n;j++){
				if(findroad(i,j)==2){
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
} 
