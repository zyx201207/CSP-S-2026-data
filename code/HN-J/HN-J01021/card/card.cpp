#include<bits/stdc++.h>
using namespace std;
#define int long long
int x[500010];
int ans[300010];
int y[500010],wz[300010],t=0;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	for(int i=1;i<=n;i++){
		//cout<<i<<":\n"; 
		for(int j=1;j<=m;j++)wz[j]=0;
		t=0;
		for(int j=i;j<=n;j++){
			if(wz[x[j]]){
				for(;t>wz[x[j]];t--)wz[y[t]]=0;
			}else{
				y[++t]=x[j];
				wz[x[j]]=t;
			}
		}
		for(int j=1;j<=t;j++){
			ans[y[j]]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
} 
