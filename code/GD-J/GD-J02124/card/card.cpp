#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m,a[50010],w[30010]={0},i,j,k;
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	for(i=1;i<=n;i++){
		int p[30010]={0},x[30010]={0},b[50010];
		for(j=i;j<=n;j++){
			if(p[a[j]]==0){
				p[a[j]]=1;
				x[a[j]]=j;
				b[j]=a[j];
			}else{
				b[x[a[j]]]=a[j];
				for(k=x[a[j]]+1;k<=j;k++){
					b[k]=0;
				}
			}
		}
		for(j=i;j<=n;j++){
			w[b[j]]++;
		}
	}
	for(i=1;i<=m;i++){
		cout<<w[i]<<' ';
	}
	return 0;
}
