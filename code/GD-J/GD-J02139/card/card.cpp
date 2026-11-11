#include<bits/stdc++.h>
using namespace std;
int n,m,a[500004],mo[500004];
bool vis[300004];
int ans[300004];
int  clean(){
	for(int i=1;i<=500004;i++){
		vis[i]=0;
		mo[i]=0;
	}
	return 0;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int p=1;
	while(p<=n){
		for(int i=p;i<=n;i++){
			if(vis[a[i]]==0){
				vis[a[i]]=1;
				mo[i]=a[i];
			}else{
				for(int j=1;j<=i;j++){
					if(mo[j]==a[i]){
						for(int k=j;k<=i;k++){
							vis[mo[k]]=0;
							mo[k]=0;
						}
						mo[i]=a[i];
						vis[a[i]]=1;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			ans[mo[i]]++;
		}
		p++;
		clean();
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
}
