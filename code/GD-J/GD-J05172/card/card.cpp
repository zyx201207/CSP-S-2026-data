#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,arr[N],ans[N],vis[N],pos[N];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>arr[i];
	for(int i=1;i<=n;i++){
//		cout<<"µÚ"<<i<<"¾Ö"<<endl; 
		for(int j=i;j<=n;j++){
			int x=arr[j];
			if(vis[x]==0){
				vis[x]=1;
				pos[x]=j-i+1;
			}else if(vis[x]==1){
				for(int k=1;k<=n;k++){
					if(vis[k]==1&&k!=j){
						if(pos[k]>pos[x]) vis[k]=0,pos[k]=0;
					}
				}
				pos[x]=j-i+1;
			}
		}
		for(int i=1;i<=m;i++){
			if(vis[i]==1){
				ans[i]++;
//				cout<<i<<"´æ»î"<<endl; 
			}
		}
//		cout<<endl;
		memset(vis,0,sizeof vis);
		memset(pos,0,sizeof pos);	
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
