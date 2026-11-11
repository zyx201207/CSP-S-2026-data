#include<bits/stdc++.h>
using namespace std;

int n,m;
long long a[10000],b[10000],c[10000],d=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n;i++){  
		for(int j=1;j<=n;j++){
			b[j]=a[i];
		}	
		for(int x=1;x<=n;x++){
			for(int j=i+1;j<=n;j++){
				if(b[x]==b[j]){
					for(int y=x;y<j;y++){
						b[y]=0;
					}
				}
			}
			for(int x=1;x<=m;x++){
				for(int j=1;j<=n;j++){
					if(b[j]==x){
						c[x]++;
					}
				}
			}
			for(int x=1;x<=n;x++){
				b[x]=0;
			} 		
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
} 
