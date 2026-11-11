#include<bits/stdc++.h>
using namespace std;
int a[500005],vis[300005],ans[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		int place;
		memset(vis,0,sizeof vis);
		for(int j=i;j<=n;j++){
			if(vis[a[j]]){
				//cout << place << endl;
				for(int k=place;k<j;k++) vis[a[k]]=0;
			}
			vis[a[j]]=1;
			place=j;
			//cout << vis[1] << vis[2] << vis[3] << endl;
		}
		for(int j=1;j<=m;j++){
			if(vis[j]) ans[j]++; 
		}
		cout << "---\n";
	}
	for(int i=1;i<=m;i++) cout << ans[i] << ' ';
	return 0;
}
