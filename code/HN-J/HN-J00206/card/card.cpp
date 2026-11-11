#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500005],mp[300005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	for(int i = 1;i <= n;i++){
		map<int,bool>vis;
		for(int j = i;j <= n;j++){
			for(int k = j-1;k >= i;k--){
				if(vis[k]==0&&a[k]==a[j]){
					for(int q = k;q <= j-1;q++){
						vis[q]=1;
					}
					break;
				}
			}
		}
		for(int j = i;j <= n;j++){
			if(vis[j]==0){
				mp[a[j]]++;
			}
		}
	}
	for(int i = 1;i <= m;i++){
		cout<<mp[i]<<" ";
	}
	return 0;
}
