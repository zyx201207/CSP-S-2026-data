#include<bits/stdc++.h>
using namespace std;
int a[500005];
int v[300005];
int tx[500005];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,man=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}

	for(int z=1;z<=n;z++){
		for(int i=z;i<=n;i++){
			man = max(man,a[i]);
			if(tx[a[i]]==0){
				tx[a[i]]= i;
			}
	
			else{
				for(int j=1;j<=man;j++){
					if(tx[j]>tx[a[i]]){
						tx[j]=0;
					}
				}
			}
			
		}
		for(int j=1;j<=man;j++){
				if(tx[j]!=0){
				v[j]++;
			}
		}
		for(int j=1;j<=man;j++){
				tx[j]=0;
			}
		}
		

	for(int i=1;i<=m;i++){
		cout<<v[i]<<" ";
	}
	return 0;
} 



