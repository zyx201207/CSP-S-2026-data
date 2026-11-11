#include<bits/stdc++.h>
using namespace std;
int a[500005],b[500005];
int syg[300005];
int lb[500005],lt;
int ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		lt=0;
		memset(syg,0,sizeof syg);
		for(int j=i;j<=n;j++){
			if(syg[a[j]]&&syg[a[j]]<=lt&&lb[syg[a[j]]]==a[j]){
				lt=syg[a[j]]-1;
			}
			syg[a[j]]=++lt;
			lb[lt]=a[j];
		}
		for(int j=1;j<=lt;j++){
			ans[lb[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}

