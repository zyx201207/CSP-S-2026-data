#include<bits/stdc++.h>
using namespace std;
int n,m,s,ans;
int num[32],akcsp[32][200005];
bool vis[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;++i){
		cin >> s;
		for(int j=0;j<=31;++j){
			if(s&(1<<j)){
				num[j]++;
				akcsp[j][i]=1; 
			}
		}
	}
	for(int j=31;j>=0;--j){
		for(int i=1;i<=n;++i){
			if(vis[i]==1&&akcsp[j][i]==1)num[j]--;
		}
		if(num[j]>=m){
			ans+=(1<<j);
			for(int i=1;i<=n;++i){
				if(akcsp[j][i]!=1)vis[i]=1;
			}
		}
	}
	cout << ans;
	return 0;
}

