#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int c[n+5];
	for(int i=1;i<=n;++i)
	cin>>c[i];
	int a[n+5],b[m+5];
	for(int i=1;i<=n;++i){
		int x=1;
		for(int j=i+1;j<=n;++j){
			a[x]=c[j];
			for(int k=1;k<x;++k){
				if(a[k]==a[x]){
					x=k;
				}
			}
		}
		for(int j=1;j<=n;++j){
			b[m]++;
		}
	}
	for(int i=1;i<=m;++i){
		cout<<b[i]<<" ";
	}
	return 0;
}
