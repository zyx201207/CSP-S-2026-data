#include<bits/stdc++.h>
using namespace std;\
int n,m;
int cnt[500005],a[500005],x[500005];
bool vis[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int i=1;i<=n;i++){
		memset(vis,true,sizeof(vis));
		memset(x,-1,sizeof(x));
		for(int j=i;j<=n;j++){
			x[j]=a[j];
			bool p=false;
			for(int k=1;k<j;k++){
				if(x[k]==x[j]){
					p=true;
					
				}	
					
			}
			if(p){
				for(int k=1;k<j;k++){
					x[k]=-1;
				}
			}
			
		}
		for(int j=1;j<=n;j++){
			for(int k=1;k<=m;k++){
				if(x[j]==k){
					
					cnt[k]++;
					break;
				}	
			}
		}
		
	}
	cout<<endl;
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
}
