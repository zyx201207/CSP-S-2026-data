#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[500005];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int sum[300005]={0};
	for(int i=0;i<n;i++){
		int b[500005]={0};
		int u=0;
		for(int j=i;j<n;j++){
			b[u]=a[j];
			for(int z=0;z<u;z++){
				if(b[z]==b[u]){
					for(int z1=z;z1<u;z1++){
						b[z1]=-1;
					}
				}
			}
			u++;
		}
		for(int j=0;j<=u;j++){
			if(b[j]!=-1){
				sum[b[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<" ";
	}
	return 0;
} 
