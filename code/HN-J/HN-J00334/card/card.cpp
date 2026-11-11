#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define endl '\n'
using namespace std;
const int N=5e5+5;
int n,m;
int a[N];
int ans[N];
unordered_map<int,int> vis;
int dq[N],cnt;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int game=1;game<=n;game++){
		cnt=0;
		vis.clear();
		for(int i=game;i<=n;i++){
			if(vis[a[i]]==0){
				vis[a[i]]=1;
				dq[++cnt]=a[i];
			}else{
				while(1){
					int tmp=dq[cnt];
					if(tmp==a[i]){
						break;
					}
					vis[tmp]=0;
					cnt--;
				}
			}
		}
		while(cnt!=0){
			int tmp=dq[cnt];
			ans[tmp]++;
			cnt--;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
/*
ÓÎ¼Ç or ÓÎ¼Ä £¿ 
4 3
1 2 1 3
*/
