#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

int n,m,a[200010],b[200010],z=1,c[200010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		z=1;
		for(int j=i;j<=n;j++){
			for(int k=1;k<=z;k++){
				if(b[k]==a[j]){
					z=k;
					break;
				}
			}
			b[z++]=a[j];
		}
		for(int j=1;j<z;j++){
			for(int k=1;k<=m;k++){
				if(b[j]==k){
					c[k]++;
					break;
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
