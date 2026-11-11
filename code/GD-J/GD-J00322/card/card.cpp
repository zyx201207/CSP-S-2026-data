#include<bits/stdc++.h>
using namespace std;
int a[100050];
int vis[100050];
int b[1000050];
int main(){
	int n,m;
	cin>>n>>m;
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=i;k<j;k++){
				if(vis[k]==0&&a[k]==a[j]){
					for(int q=k;q<j;q++){
						vis[q]=1;
					}
				}
			}
		}
		for(int j=i;j<=n;j++){
			if(vis[j]==0){
				b[a[j]]++;
			}
		}
		for(int j=1;j<=n;j++){
			vis[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
