#include<bits/stdc++.h>
using namespace std;
long long q[5*100000+5],rear=1,m,n,n1=1,a[3*100000+5],size[3*100000+5]={};
bool vis[3*100000+5];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	n1=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	while(n1<=n){
		memset(vis,0,sizeof vis);		
		memset(q,0,sizeof q);
		rear=1;
		for(int i=n1;i<=n;i++){
			if(!vis[a[i]]){
				q[rear]=a[i];
				rear++;
				vis[a[i]]=true;	

			}else{
				for(int j=1;j<=n;j++){
					if(q[j]==a[i]){
						rear=j+1;
					}
					if(j>=rear){
						vis[q[j]]=false;
					}
				}
				
			}
		}
		for(int j=1;j<rear;j++){
			size[q[j]]++;
		}
		n1++;

	}
	for(int i=1;i<=m;i++){
		cout<<size[i]<<" ";
	}
	return 0;
}
