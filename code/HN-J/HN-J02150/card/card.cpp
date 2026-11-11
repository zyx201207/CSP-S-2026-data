#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[1000005],p[1000005],cnt,vis[1000005],b[1000005],sum;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(p,0,sizeof(p));
		cnt=0;
		for(int j=i;j<=n;j++){
			cnt++;
			p[cnt]=a[j];
			for(int k=1;k<cnt;k++){
				if(p[k]==a[j]){
					cnt=k;
					break;
				}
			}
		}
		for(int l=1;l<=cnt;l++){
			vis[p[l]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<vis[i]<<" ";
	}
	return 0;
}

