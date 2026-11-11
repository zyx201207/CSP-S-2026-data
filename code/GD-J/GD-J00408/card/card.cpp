#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],f[300005],c[500005],ans[300005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int ve[500005],cnt=0;
		for(int i=1;i<=m;i++)f[i]=0;
		for(int j=i;j<=n;j++){
			ve[++cnt]=a[j];
			if(f[a[j]]==1){
				ve[cnt--]=0;
				while(ve[cnt]!=a[j])ve[cnt--]=0;
				ve[cnt--]=0;
				ve[++cnt]=a[j];
			}
			else f[a[j]]=1;
		}
		for(int k=1;k<=cnt;k++){
			ans[ve[k]]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
