#include<bits/stdc++.h>
using namespace std;
int a[500005],c[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n,m;cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){ 
		int b[300005];
		long long x=0;
		for(int j=i;j<=n;j++){
			for(int k=1;k<x;k++){
				if(b[k]==a[j]){
					x=k-1;
				}
			}
			x++;
			b[x]=a[j];
		}
		for(int j=1;j<=x;j++){
			c[b[j]]++; 
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
