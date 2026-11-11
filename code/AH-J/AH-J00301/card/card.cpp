#include<bits/stdc++.h>
using namespace std;
int n,m,a[50005],i,s,x[50005],y,z;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int j=1;j<=n;j++){
		cin>>a[j];
	}
	int b[m+5],c[m+5],ans[m+5];
	while(i<=n){
	for(int j=1;j<=n;j++){
		x[j]=a[j];
	}
	i++;
	for(int j=j-i+1;j<=n;j++){
			s=x[j];
			b[s]++;
			if(b[s]>1){
				y=c[s];
				z=j-1;
				for(int k=y;k<=z;k++){
					x[k]=0;
					b[k]=0;
				}
				continue;
			}
			c[s]=j;			
		}
		for(int j=1;j<=n;j++){
			for(int k=1;k<=m;k++){
				if(x[j]==k)ans[k]++;
			}
		}
	}
	for(int j=1;j<=m;j++){
		cout<<ans[j]<<" ";
	}
	
}

