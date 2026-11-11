#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;
const int N=2e5+5;
int n,m,cnt[N],a[N];
bool g[35][N];
bool flag[N],vis[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	int mx=0;
	for(int i=1;i<=n;i++){
		flag[i]=1;
		cin >> a[i];
		int res=0;
		int x=a[i];
		while(x){
			if(x&1){
				g[res][i]=1;
				cnt[res]++;
			}
			x/=2;
			res++;
		}
		mx=max(mx,res);
	}
	int ans=0;
	for(int i=mx-1;i>=0;i--){
		if(cnt[i]<m) continue;
		int res=0;
		for(int j=1;j<=n;j++){
			vis[j]=flag[j]&g[i][j];
			res+=vis[j];
		}
		if(res<m) continue;
		for(int j=1;j<=n;j++){
			flag[j]=vis[j];
		}
		ans|=(1<<i);
	}
	cout << ans;
	return 0;
} 
