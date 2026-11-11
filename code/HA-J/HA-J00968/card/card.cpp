#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[10000000],b[1000000],c[1000000]={0};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			b[j]=a[j];
		}
		for(int j=i-1;j<=n;j++){
			for(int x=i+1;x<n+1;x++){
				if(a[j]==a[x]){
					for(int v=j;v<=x-1;v++){
						b[v]=0;
					}
				}
			}
		}
		for(int j=1;j<n;j++){
			for(int x=i+1;x<n+1;x++){
				if(a[j]==a[x]){
						b[j]=0;
						b[x]=0;
				}
			}
		}
		for(int s=1;s<=n;s++){
			if(b[s]>0){
				c[a[s]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		if(i=1) c[i]+=1;
		cout<<c[i];
	}
	return 0;
}
