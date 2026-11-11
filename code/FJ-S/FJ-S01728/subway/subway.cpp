#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],k[500005],a[500005],t[500005],wt[505][505];
int g = 2000000005;
int work_out(int str,int en){
	int ans = wt[str][en];
	if (ans == g){
		for (int i = 1;i <= n;i++){
			if (wt[str][i] != g) ans = min(ans,work_out(i,en)+wt[str][i]);
		}
	}
	return ans;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for (int i = 1;i <= m;i++) cin>>w[i];
	for (int i = 1;i <= m;i++) for (int j = 1;j <= m;j++) wt[i][j] = g;
	for (int i = 1;i <= n;i++){
		cin>>k[i];
		for (int j = 1;j <= k[i];j++) cin>>a[j]>>t[j];
		for (int j = 1;j <= k[i];j++){
			for (int o = j + 1;o <= k[i];o++){
				wt[a[j]][a[o]] = min(wt[a[j]][a[o]],t[j]+t[o]);
				wt[a[o]][a[j]] = wt[a[j]][a[o]];
			}
		}
	}
	for (int i = 1;i <= q;i++){
		int x,y;
		cin>>x>>y;
		cout<<work_out(x,y)+w[x]+w[y]<<"\n";
	}
}
