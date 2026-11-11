#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+9,M=3e5+9;
int a[N],pos[N],c[N];
bool vis[M];
ll ans[M];
void solved(){
	int n,m; cin >> n >> m;
	for(int i=1;i<=n;i++)cin >> a[i];
	for(int i=1;i<=m;i++){
		int cnt=1;
		for(int j=i;j<=n;i++){
			if(vis[a[j]]){
				for(int k=pos[a[j]];k<=cnt;k++){
					vis[c[k]]=false;
					c[k]=0;
				}
				cnt=pos[a[j]];
			}
			c[cnt]=a[j];
			vis[a[j]]=true;
			pos[a[j]]=cnt;
			cnt++;
		}
		for(int j=1;j<=m;j++)if(vis[j])ans[j]++,vis[j]=false;
	}
	for(int i=1;i<=m;i++)cout << ans[i] << " "; 
}
int main(){
	freopen("card1.in","r",stdin);
	freopen("card1.out","w",stdout);
//	int t; cin >> t; while(t--)
	solved();
	return 0;
}


