#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],cnt[300005],b[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(b[i]!=0){
				if(b[i]==b[j]){
					for(int z=i+1;z<=j;z++){
						b[z]=0;
					}
				}	
			}
		}
		for(int j=1;j<=m;j++){
			for(int z=1;z<=n;z++){
				if(b[z]==j){
					cnt[j]++;
				}
			}
		}
		for(int j=1;j<=n;j++){
			b[j]=a[j];
		}
	}
	
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
	


