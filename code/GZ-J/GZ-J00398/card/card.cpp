//华东师范大学附属贵阳学校 刘睿羽 GZ-J00398   
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10;
int n,m;
int vis[N];
int a[N];
int s[N]; 
int f[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for (int i=1;i<=n;i++){
    	cin>>a[i];
	}
	for (int i=1;i<=n;i++){
		for (int j=i;j<=n;j++){
			vis[a[j]]++;
			if (vis[a[j]]>=2){
				for (int z=1;z<=m;z++) vis[z]=0;
				vis[a[j]]=1;
			}
		}
		for (int j=1;j<=m;j++){
			if (vis[j]==1) f[j]++;
		}
		for (int z=1;z<=m;z++) vis[z]=0;
	}
	for (int i=1;i<=m;i++) cout<<f[i]<<" ";
	return 0; 
}

