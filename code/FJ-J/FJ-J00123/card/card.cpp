#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005]={0};
int d[300005]={0};
int c[2][500005]={0},q=1,z,minn=300005,maxx=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int k=1;k<=n;k++){
		z=k;
		q=1;
		minn=300005;
		maxx=0;
		while(z<=n){
			if(c[0][a[z]]==0){
				c[0][a[z]]=q;
				c[1][a[z]]=z;
				if(a[z]>maxx){
					maxx=a[z];
				}
				if(a[z]<minn){
					minn=a[z];
				}
				q++;
			}else{
				for(int i=minn;i<=maxx;i++){
					if(c[0][i]>c[0][a[z]]){
						c[0][i]=0;
						c[1][i]=0;
					}
				}
				q=c[0][a[z]]+1;
			}
			z++;
		}
		for(int i=minn;i<=maxx;i++){
			if(c[0][i]!=0){
				d[i]++;
				c[0][i]=0;
				c[1][i]=0;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<d[i]<<" ";
	}
	return 0;
}
