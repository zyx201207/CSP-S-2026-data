#include<bits/stdc++.h>
using namespace std;
long long n,m,arr[1000100],anstong[1000100];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	} 
	for(int i=1;i<=n;i++){
		bool vis[1000100];
		memset(vis,false,1000100);
		for(int j=i;j<=n;j++){
			for(int k=i;k<=j;k++){
				if(arr[j]==arr[k]&&!vis[k]){
					for(int l=k+1;l<=j;l++){
						vis[l]=1;
					}
				}
			}
		}
		for(int p=i;p<=n;p++){
			if(!vis[p]){
				anstong[arr[p]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<anstong[i]<<' ';	
	}
	return 0;
}

