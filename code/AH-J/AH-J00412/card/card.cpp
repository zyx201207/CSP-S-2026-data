#include<iostream>
#include<cstdio>
using namespace std;
int vis[1000005],n=1,m,a[1000005],cnt,t[1000005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(vis[a[j]]!=0){
				cnt=vis[a[j]];
				for(int k=1;k<=m;k++){
					if(vis[k]>vis[a[j]]){
						vis[k]=0;
					}
				}
			}else{
				vis[a[j]]=j;
			}
		}
		for(int j=1;j<=m;j++){
			if(vis[j]){
				t[j]++;
				vis[j]=0;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]<<" ";
	}
}
