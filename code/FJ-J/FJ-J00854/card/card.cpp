#include <bits/stdc++.h>
using namespace std;

int vis[500010],dis[500010],a[500010];
int n,m;

int main(){
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdin);
	
	cin >> n >> m;
	for (int i = 1;i<=n;i++){
		cin >> a[i];
	}
	int ans;
	for (int k = 1;k<=n;k++){
		ans=k;
		for (int i = k;i<=n;i++){
			if (vis[a[i]]==1){
				ans=i;
			}
			else{
				vis[a[i]]=1;
			}
		}
		for (int ans = k;ans<=n;ans++){
			dis[a[ans]]++;
		}
	}
	
	for (int i = 1;i<=m;i++){
		cout << dis[i] << ' ';
	}
	
	return 0;
}
