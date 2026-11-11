#include<bits/stdc++.h>
using namespace std;
int card[200005];
bool vis[100005];
bool way[100005];
int bat[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		scanf("%d",&card[i]);
	}
	for(int i=0;i<n;i++){
		memset(vis,0,sizeof(vis));
		memset(way,0,sizeof(way));
		int rt=i;
		for(int j=i;j<n;j++){
			if(vis[card[j]]){
				for(int k=j-1;k>=0;k--){
					if(card[k]==card[j]&&way[k]==1){
						way[k]=0;
						break;
					}
					way[k]=0;
				}
				way[j]=1;
			}
			else{
				vis[card[j]]=1;
				way[j]=1;
			}
		}
		for(int j=i;j<n;j++){
			if(way[j]){
				bat[card[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<bat[i]<<" ";
	}
	return 0;
}
