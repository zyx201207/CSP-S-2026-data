#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],x[500005],f[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			x[a[j]]++;
			if(x[a[j]]>1){
				for(int o=1;o<=n;o++){
					x[o]=0;
				}
				x[a[j]]=1;
			}
		}
		for(int j=1;j<=n;j++){
			if(x[j]==1){
				f[j]++;
			}
		}
		for(int j=1;j<=n;j++){
			x[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<f[i]<<" ";
	}
	return 0;
}

