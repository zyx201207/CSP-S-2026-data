#include<bits/stdc++.h>
using namespace std;
int m,n;
int a[5005],b[3005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int c[5005],v=1;
		for(int j=0;j<5005;j++) c[j]=0;
		for(int j=i;j<=n;j++){
			for(int k=1;k<v;k++){
				if(c[k]==a[j]){
					for(int l=k;l<v;l++){
						c[k]=0;
					}
					v=k;
				}
			}
			c[v]=a[j];
			v++;
		}
		for(int j=1;j<v;j++){
			b[c[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
}
