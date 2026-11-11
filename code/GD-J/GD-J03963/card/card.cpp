#include <bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
long long a[MAXN],n,app[MAXN],cnt[MAXN],m;
bool vis[MAXN];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >>m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		memset(app,0,sizeof(app));
		for(int j=i;j<=n;j++){
			if(vis[a[j]]){
				for(int k=app[a[j]];k<=j;k++){
					vis[a[k]]=0;
					app[a[k]]=0;
				}
			}
			vis[a[j]]=1;
			app[a[j]]=j; 
		}
		for(int i=1;i<=n;i++){
			if(vis[i])cnt[i]++;
		}
	}
	for(int i=1;i<=m;i++)cout << cnt[i]<< " ";
} 
