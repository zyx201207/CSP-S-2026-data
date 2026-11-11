#include<bits/stdc++.h>
using namespace std;
int n,m;
int na[500005],ma[400004],cnt[400004];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>na[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			ma[j]=na[j];
			for(int k=1;k<j;k++){
				if(ma[k]==ma[j]){
					for(int z=k+1;z<=j;z++){
						ma[z]=-1;
					}
				}
			}
		}
		
		for(int j=1;j<=m;j++){
			for(int k=1;k<=n;k++){
				if(ma[k]==j){
					cnt[j]++;
					ma[k]=-1;
				}
			}
		}	
	}
	for(int j=1;j<=m;j++)cout<<cnt[j]<<' ';
	return 0;
}
