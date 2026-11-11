#include<bits/stdc++.h>
using namespace std;
int a[500050],b[300010],k[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int c[300010];
		for(int j=1;j<=m;j++){
			b[j]=0;
		}
		for(int j=i;j<=n;j++){
			if(c[a[j]]!=0){
				for(int d=c[a[j]];d<=j-1;d++){
					b[a[d]]=1;
				}
			}
			c[a[j]]=j;
			b[a[j]]=2;
		}
		for(int j=1;j<=m;j++){
			if(b[j]==2){
				k[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<k[i]<<" ";
	}
	return 0;
}

