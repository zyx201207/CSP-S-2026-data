#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],b[500005],vis[300005],v[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		for(int j=i;j<=n;j++){
			if(vis[b[j]]!=0){
				for(int k=vis[b[j]];k<j;k++){
					vis[b[k]]=0;
					b[k]=0;
				}
				vis[b[j]]=j;
			}
			else{
				vis[b[j]]=j;
			}
		}
		for(int j=1;j<=n;j++){
			if(vis[j]!=0){
				v[b[vis[j]]]++;
			}
			b[j]=a[j];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<v[i]<<" "; 
	}
	return 0;
}
