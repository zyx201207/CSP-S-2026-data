#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],p[500005],k[500005];
void ff(int w,int h,int l){
	for(int d=w;d<h;d++){
		if(k[d]==l){
			for(int u=d;u<h;u++){
				k[u]=0;
			}break;
		}
	}return ;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}for(int i=0;i<n;i++){
		memset(k,0,sizeof k);
		for(int j=i+1;j<=n;j++){
			k[j]=a[j];
			ff(i+1,j,a[j]);
		}for(int j=i+1;j<=n;j++){
			if(k[j]!=0){
				p[k[j]]++;
			}
		}
	}for(int i=1;i<=m;i++){
		cout<<p[i]<<" ";
	}return 0;
}
