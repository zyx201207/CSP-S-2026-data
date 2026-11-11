#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],c[500005],vis[500005],d[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int j=1;j<=n;j++){
		memset(b,0,sizeof(b));
		memset(vis,0,sizeof(vis));
		int len=0;
		for(int i=j;i<=n;i++){
			memset(c,0,sizeof(c));
			b[++len]=a[i];
			bool yes=true;
			int t;
			for(int z=1;z<=i-j;z++){
				if(b[z]==a[i]&&vis[z]!=1){
					t=z;
					yes=false;
					break;
				}
			}
			if(yes==false){
				len=t;
				for(int z=1;z<t;z++){
					c[z]=b[z];
				}
				for(int j=1;j<t;j++){
					b[j]=c[j];
				}
				b[len]=a[i];
				vis[i]=1;
			}
			
		}
		for(int i=1;i<=len;i++){
			d[b[i]]++;
		}
	} 
	for(int i=1;i<=m;i++){
		cout<<d[i]<<" ";
	}
	return 0;
}

