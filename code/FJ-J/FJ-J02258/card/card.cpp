#include<bits/stdc++.h>
using namespace std;

int a[500005],b[300005];
int z[300005];
bool c[300005];

void solve(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int zj=0;
		for(int j=i;j<=n;j++){
			if(c[a[j]]){
				while(z[zj]!=a[j]){
					c[z[zj]]=false;
					zj--;
				}
			}else{
				zj++;
				z[zj]=a[j];
				c[a[j]]=true;
			}
		}
		for(int j=1;j<=zj;j++){
			b[z[j]]++;
			c[z[j]]=false;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	} 
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
