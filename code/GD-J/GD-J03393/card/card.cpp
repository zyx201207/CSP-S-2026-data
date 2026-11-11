#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300005],f[500005],ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	memset(ans,0,sizeof(ans));
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(b,0,sizeof(b));
		memset(f,0,sizeof(f));
		int sum=0;
		for(int j=i;j<=n;j++){
			if(b[a[j]]==0){
				sum++;
				f[sum]=a[j];
				b[a[j]]++;
			}else{
				bool strat=0;
				for(int k=1;k<=n;k++){
					if(f[k]==a[j]) strat=1;
					if(strat==1){
						f[k]=0;
						sum--;
						b[f[k]]--;
					}
				}
				sum++;
				f[sum]=a[j];
				b[a[j]]++;
			}
		}
		for(int j=1;j<=m;j++){
			if(b[j]!=0) ans[j]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 
