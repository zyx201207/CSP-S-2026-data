#include <bits/stdc++.h>
using namespace std;
int a[500005];
int b[500005];
long long c[500005];
int g[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			b[i]=a[i];
	    }
		for(int j=i;j<=n;j++){
			bool f=false;
			for(int k=i;k<=n;k++){
				if(b[k]==a[j]){
					for(int u=k+1;u<=n;u++){
						b[u]=-1;
				    }
				    f=true;
				}
			}
			if(!f){
				n++;
				b[n]=a[j];
			}
		}
		for(int p=1;p<=n;p++){
			if(b[p]==-1){
		        continue;
			}else{
			  	c[p]++;
			  	b[p]=0;
			}
		}
    }
    for(int i=1;i<=m;i++){
    	cout<<c[i]<<" ";
    }
	return 0;
}
