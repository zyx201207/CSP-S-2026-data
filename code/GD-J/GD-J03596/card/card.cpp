#include<bits/stdc++.h>
using namespace std;
int n,m,c[500005],ans=0;
int record[400005];
int vis[300005],dir[300005];
int main(){

	cin>>n>>m;
	memset(record,0,sizeof(record));
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		memset(dir,0,sizeof(dir));
		int l=0;
		for(int j=i;j<=n;j++){
			if(vis[c[j]]==0){
				dir[++l]=c[j];
				vis[c[j]]=l;
				
			}else{
				int ol=l;
				l=vis[c[j]];
				for(int k=vis[c[j]]+1;j<=ol;j++){
					vis[k]=0;
					dir[k]=0;
				}
			}
		}
		for(int j=1;j<=l;j++){
			record[dir[j]]++;
		}
	}
	
	for(int i=1;i<=m;i++){
		cout<<record[i]<<" ";
	}
	return 0;
}
