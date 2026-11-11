#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100010],b[100010]={0};
bool c[100010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			c[j]=0; 
		}
		for(int j=n;j>=i;j--){
			for(int k=j-1;k>=i;k--){
				if(a[j]==a[k]){
					for(int g=k;g<j;g++){
						c[g]=1;
					}
				}
			}
		}
		for(int j=i;j<=n;j++){
			if(c[j]!=1){
				b[a[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	} 
	return 0;
}
