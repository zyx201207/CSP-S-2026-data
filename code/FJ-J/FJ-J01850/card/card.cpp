#include<bits/stdc++.h>
using namespace std;
int n,m,a[5005],lent,tmp[5005],ans[5005],vis[5005];
int main(){
	//CHECK IT FIRST
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int k=1;k<=n;k++){
		memset(tmp,0,sizeof(tmp));
		memset(vis,0,sizeof(tmp));
		lent=0;
		for(int p=k;p<=n;p++){lent++;
			for(int i=1;i<=lent;i++){
				if(tmp[i]==a[p]){
					for(int kl=i;kl<=lent;kl++){
						tmp[kl]=0;
					}
					lent=i;	
				}
			}
			tmp[lent]=a[p];
			
			//for(int i=1;i<=lent;i++) cout<<tmp[i]<<" ";
			//cout<<endl;
		}
		//cout<<"ans:";
		//for(int i=1;i<=lent;i++) cout<<tmp[i]<<" ";
		//cout<<endl;
		for(int i=1;i<=m;i++) ans[tmp[i]]+=1;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
//I love playing phigros.
//RP++;RP++;RP++;
//what do I(want) more than a happy ending.
