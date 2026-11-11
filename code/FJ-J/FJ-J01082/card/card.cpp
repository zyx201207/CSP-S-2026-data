#include<bits/stdc++.h> 
using namespace std;
int n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >>n>>m;
	int a[n+1];
	int b[m+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int c[n+1-i+1]={0},d[n+1-i+1]={0},z=1;
		for(int j=1;j<=n+1;j++){
			int x=a[j];
			if(d[x]==0){
				c[z]=x,d[x]=z;
				z++;
			}
			else{
				z=d[x];d[x]=z;
				for(int k=z+1;k<=n+1-i+1;k++){
					c[k]=0;
				}
			}
		}
		for(int j=1;j<n+1-i+1;j++){
			if(c[j]!=0)
			b[j]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
