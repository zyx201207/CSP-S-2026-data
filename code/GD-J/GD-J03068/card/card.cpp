#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],xs[300010],ds[300010],e,b[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int k=1;k<=n;k++){
		memset(xs,0,sizeof(xs));
		for(int i=k;i<=n;i++){
			if(xs[a[i]]==0) {
				xs[a[i]]=++e;
				b[e]=a[i];
			}
			else {
				for(int j=xs[a[i]]+1;j<=e;j++){
					xs[b[j]]=0;
					b[j]=0;
				}
				e=xs[a[i]];
			}
		}
		for(int i=1;i<=e;i++){
			ds[b[i]]++;
			b[i]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ds[i]<<" ";
	}
	return 0;
}
