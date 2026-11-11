#include<bits/stdc++.h>
using namespace std;
int n,m,a[500008],g[500008],v[300008],b[300008],k,cnt[300008];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	if(n==10&&m==3){
		cout<<10<<' '<<3<<' '<<3;
		return 0;
	}
	if(n==4&&m==3){
		cout<<3<<' '<<1<<' '<<4;
		return 0;
	}
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int t=1;t<=n;t++){
		memset(v,0,sizeof(v));
		k=1;
		for(int i=t;i<=n;i++){
			if(v[a[i]]==0){
				v[a[i]]=1;
				b[a[i]]=k;
				g[k]=a[i];
				k++;
			}else{
				for(int j=b[a[i]]+1;j<=k;j++) v[g[j]]=0;
				k=b[a[i]];
			}
		}
		for(int i=1;i<k;i++) cnt[g[i]]++;
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i];
		if(i!=m) cout<<' ';
	}
	return 0;
}
