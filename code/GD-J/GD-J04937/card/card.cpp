#include<bits/stdc++.h>
using namespace std;
int p[10000];
bool vis[100];
int s[100];
int z[10000];
void qk(int n){
	for(int i=1;i<=n;i++){
		z[i]=0;
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>p[i];
	}
	for(int i=1;i<=n;i++){
		qk(n);
		for(int j=1;j<=n;j++){
			if(j==i-1)continue;
			z[j]=p[j]; 
			if(vis[p[j]]==0){
				vis[p[j]]=1;
			}else{
				int ll=0;
				for(int k=1;k<j;k++){
					if(ll==1){
						vis[z[k]]=0;
						z[k]=0;
					}else{
						if(z[k]==p[j]){
							ll=1;
						}
					}
				}
			}
		}
		for(int l=1;l<=m;l++){
			if(vis[l])s[l]++;
		}
	}
	for(int i=1;i<m;i++)cout<<s[i]<<endl;
	return 0;
}
