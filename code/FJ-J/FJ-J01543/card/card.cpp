#include<bits/stdc++.h>
using namespace std;
int n,m,arr[500005],ans[500005],vis[500005],k[500005],judge1=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		if(arr[i]>arr[i+1]) judge1=0;
	}
	if(judge1){
		for(int i=1;i<n;i++){
			if(arr[i]!=arr[i+1]) ans[arr[i]]=i;
		}
		ans[arr[n]]=n;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			ans[arr[i]]++;
			if(arr[n]!=arr[i]) ans[arr[n]]++;
		}
	}else{
		for(int i=n;i>=1;i--){
			if(!vis[arr[i]]) vis[arr[i]]=i;
		}
		for(int i=1;i<=n;i++){
			int p=arr[i];
			memset(k,0,sizeof(k));
			for(int j=vis[p];j<=n;j++){
				j=vis[arr[j]];
				if(k[arr[j]]==0) ans[arr[j]]++;
				k[arr[j]]=1;
			}
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
