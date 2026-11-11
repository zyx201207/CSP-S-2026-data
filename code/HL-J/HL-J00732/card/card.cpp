#include<bits/stdc++.h>
using namespace std;
int n,m,a[100059],b[100059],c[100059],d[100059],g;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i,k=0;j<=n;j++){
			k++;
			b[k]=a[j];
			if(b[c[a[j]]]){
				for(int l=c[a[j]]+1,w=k;l<=w;l++){
					b[l]=0;
					k--;
				}
			}
			c[a[j]]=k;
			g=k;
		}
		for(int j=1;j<=g;j++){
			d[b[j]]++;
		}
		for(int j=1;j<=n;j++){
			b[j]=0;
			c[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<d[i]<<" ";
	}
	return 0;
}