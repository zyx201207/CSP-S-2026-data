#include<bits/stdc++.h>
using namespace std;
int carduse[100005],cardlasttime[100005],n,m,card[100005],i,j,k,visited[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>card[i];
	}
	for(i=1;i<=n;i++){
		for(j=i;j<=n;j++){
			carduse[j]=card[j];
		}
		for(j=i;j<=n;j++){
			if(visited[carduse[j]]==0){
				visited[carduse[j]]++;
			}
			else{
				  for (k=j-1;k>=i;k--){
					 if(carduse[k]==carduse[j]){
				 		break;
					}
					for(int l=k;l<j;l++){
						carduse[l]=0;
					}  	
				}
			}
		for(j=i;j<=n;j++){
			if(carduse[j]!=0)cardlasttime[carduse[j]]++;
		}
		for(j=i;j<=n;j++){
			carduse[j]=0;
			visited[j]=0;    
		}
	}
}
	for(i=1;i<=m;i++){
		cout<<cardlasttime[i]<<' ';
	}

	return 0;
}
