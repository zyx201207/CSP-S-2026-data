#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],c[300005],d[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++){
		for (int i=1;i<=m;i++) c[i]=0;
		long long x=0;
		for (int j=i;j<=n;j++){
			x++;
			if (c[a[j]]==0){
				c[a[j]]=x;
				b[x]=a[j];
			}
			else{
				for (int y=c[a[j]]+1;y<x;y++) c[b[y]]=0;
				x=c[a[j]];
			}
		}
		for (int j=1;j<=x;j++){
			d[b[j]]++;
		}
	}
	for (int i=1;i<=m;i++){
		cout<<d[i]<<" ";
	}
	return 0;
}
