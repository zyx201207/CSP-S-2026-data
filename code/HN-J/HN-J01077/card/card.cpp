#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m; 
	int a[n+1],a1[n+1]={0};
	int b[m+1]={0};
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){	
		for(int u=1;u<=n;u++){
			a1[u]=a[u];
		}
		int b1[m+1]={0};
		int sum=i;
		for(int j=i+1;j<=n;j++){
			for(int k=i;k<j;k++){
				if(a1[j]==a1[k]){
					for(int l=k;l<j;l++){
						a1[l]=0;
					}
			} 
			} 

		}
		for(int j=i;j<=n;j++){
			if(b1[a1[j]]==0&&a1[j]!=0){
				b[a1[j]]++;
				b1[a1[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;	
}

