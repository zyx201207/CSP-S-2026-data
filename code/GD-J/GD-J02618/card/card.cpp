#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long maxx=-1e18;
long long a[600010];
long long f[600010];
long long ans[600010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(f,0,sizeof(f));
		long long cnt=0;
		for(int j=i;j<=n;j++){
			bool flag=false;
			long long poss=0;
			for(int k=1;k<=cnt;k++){
				if(f[k]==a[j]){
					flag=true;
					poss=k;
				}
				if(flag){
					f[k]=0;
				}
			}
			if(flag){
				cnt=poss;
				f[poss]=a[j];
			}
			else{
				f[++cnt]=a[j];
			}
		}
		for(int j=1;j<=cnt;j++){
			ans[f[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		if(i>1) cout<<" ";
		cout<<ans[i];
	}
	return 0;
}

