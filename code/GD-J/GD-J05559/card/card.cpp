#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],f[500005],ans[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		f[i]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			f[a[i]]++;
			if(f[a[i]]==i+1){
				for(int k=1;k<=m;k++){
					f[k]=i-1;
				}
				f[a[i]]++;
			}
		}
		for(int x=1;x<=m;x++){
			if(f[x]==i) ans[x]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
}
