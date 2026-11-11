#include<bits/stdc++.h>
using namespace std;
int cds[300050],k[500050],ncd[500050],all[300050],tcd[300050];
bool vis[300050];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>k[i];
	}
	int tmp=1;
	while(tmp<=n){
		memset(cds,0,sizeof(cds));
		memset(ncd,0,sizeof(ncd));
		memset(vis,0,sizeof(vis));
		memset(tcd,0,sizeof(tcd));
		for(int i=tmp;i<=n;i++){
			if(tcd[k[i]]==0){
				cds[k[i]]=0;
			}
			if(cds[k[i]]==0){
				cds[k[i]]=i;
				ncd[i]=k[i];
				tcd[k[i]]++;
			}else{
				for(int j=cds[k[i]];j<i;j++){
				    tcd[ncd[j]]--;
					ncd[j]=-1;
				}
				cds[k[i]]=i;
				ncd[i]=k[i];
				tcd[k[i]]++;
			}
		}
		for(int i=1;i<=n;i++){
			if(ncd[i]!=-1&&!vis[ncd[i]]){
				all[ncd[i]]++;
				vis[ncd[i]]=true;
			}
		}
		tmp++;
	}
	for(int i=1;i<=m;i++){
		cout<<all[i]<<" ";
	}
	return 0;
}
