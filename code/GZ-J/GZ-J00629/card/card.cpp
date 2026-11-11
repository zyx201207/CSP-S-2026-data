// GZ-J00629 µËÍûÔÆ
#include<bits/stdc++.h>
using namespace std;
int a[500005];
int c[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int u=a[j];
			int flag=0;
			for(int k=j+1;k<=n;k++){
				if(a[k]==a[j]){
					flag=1;
					j=k;
					break;
				}
			}
			if(!flag) c[u]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
}
