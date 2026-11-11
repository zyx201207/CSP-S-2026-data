#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int ds[300005]={0};
	int ycx[300005]={0};
	int p[500005];
	int table[500005]={0};
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	int tx=1;
	for(int i=1;i<=n;i++){
		for(int k=i;k<=n;k++){
			table[tx]=p[i];
			tx++;
			ycx[p[i]]++;
			if(ycx[p[i]>1]){
				int sum=tx;
				for(int j=i+sum;j>=i;j--){
					p[i]==0;
					tx--;
					if(p[j]==p[i])break;
				}
			}
			for(int j=1;j<=tx;j++){
				ds[table[i]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ds[i]<<" ";
	}
	return 0;
}
