#include<bits/stdc++.h>
using namespace std;
int a[500005],c[500005],f[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin.tie(NULL);
    ios::sync_with_stdio(0);
    int n,m,x=0;
    cin>>n>>m;
    int k=0,l=n;
    for(int i=1;i<=n;i++){
		cin>>a[i];
	}
    while(l--){
		int g=0;
		k++;
		x=0;
		for(int i=1;i<=n;i++){
			c[i]=0;
		}
		for(int i=k;i<=n;i++){
			g=0;
			for(int j=1;j<=x;j++){
				if(c[j]==a[i]){
					g=1;
					break;
				}
			}
			if(g==0){
				c[++x]=a[i];
			}
			else{
				while(c[x]!=a[i]){
					x--;
				} 
			}
		}
		for(int i=1;i<=x;i++){
			f[c[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<f[i]<<" ";
	}
	
    return 0;
}
