#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n],k[m],f[n],g[m];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<m;i++){
		k[i]=0;
		g[i]=-1;
	}
	for(int i=0;i<n;i++){
		for(int b=i;b<n;b++){
			f[b]=a[b];
		}
		for(int j=i;j<n;j++){
			if(g[f[j]-1]==-1){
				g[f[j]-1]=j;
			}else{
				for(int b=g[f[j]-1];b<j;b++){
					f[b]=0;
				}
				g[f[j]-1]=j;
			}
		}
		for(int b=i;b<n;b++){
			if(f[b]!=0){
				k[f[b]-1]++;
			}
		}
	}
	for(int i=0;i<m;i++){
		cout<<k[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);	
	return 0;
}
