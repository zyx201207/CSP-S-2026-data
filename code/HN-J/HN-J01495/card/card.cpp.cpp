#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[300005],c[300005][500005],res[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			b[a[j]]++;
			c[a[i]][b[a[j]]]=j;
			if(b[a[j]]==2){
				long long x,y;
				x=c[a[i]][b[a[j]]];
				y=c[a[i]][b[a[j-1]]];
				for(int k=x-1;k>=y;k--){
					b[a[k]]--;
				}
			}
		}
		for(int j=i;j<=n;j++){
			if(b[a[j]]){
				res[b[a[j]]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<res[i]<<" ";
	}
	return 0;
}
