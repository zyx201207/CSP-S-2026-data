#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[500010];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int ans;
		for(int j=i;j<=n;j++){
		for(int k=j;k<=n;k++){
			if(a[k]==a[j]){
				for(int u=j;u<k;u++){
					a[u]=0;
				}
			}
		}	
		}
		for(int p=i;p<=n;p++){
			 ans=0;
			if(a[p]==i){
				ans++;
			}
		}
		cout<<ans<<" ";
	}
	return 0;
}
