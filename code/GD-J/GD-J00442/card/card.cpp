#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100005];
int b[100005],c[100005];
int main(){
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		b[i]=i; 
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int k=1;k<=m;k++){
				bool x=true;
				if(b[k]==a[j]){
					for(int p=k+1;p<=m;p++){
						b[p]=0;
						x=false;
					}
				}
				if(k==m&&x){
					for(int o=1;o<=m;o++){
						if(b[o]==0){
							b[o]=a[j];
						}
					}
				}
			}

		}
		for(int j=1;j<=m;j++){
			cout<<b[j]<<" ";
			c[b[j]]++;
		}
		cout<<endl;
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
