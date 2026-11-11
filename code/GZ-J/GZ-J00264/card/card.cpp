//GZ-J00264 ³Âè÷Ðù
#include<bits/stdc++.h>
using namespace std;
int n,m,a[200001],vis[200001],ans[200001],k;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int q=0;q<n;q++){
		for(int i=1+q;i<=n;i+=(k+1)){
			k=0;
			for(int j=i+1;j<=n;j++){
				if(a[j]==a[i]&&vis[i]==0){
					for(k=i;k<j;k++){
						vis[k]=1;
					}
					k-=i;
					break;
				}
			}
		}
		for(int i=1+q;i<=n;i++){
			if(vis[i]==0) ans[a[i]]++;
		}

		memset(vis,0,200001);
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
