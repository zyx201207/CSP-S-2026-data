#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[1000010];
int c[1000010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int b[1000010];
		for(int j=i;j<=n;j++){
			int x=a[j];
			if(b[x]==1){
				for(int k=1;k<=m;k++){
					b[k]=0;
				}
			}
			else{
				b[x]=1;
			}
		}
		for(int j=1;j<=m;j++){
			if(b[j]==1){
				c[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<' ';
	}
	return 0;
}
