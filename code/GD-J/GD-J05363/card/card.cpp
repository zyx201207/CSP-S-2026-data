#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+10];
	int ans[n+5][m+5];
	int sum[m+5]={0};
	int map[n+5];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		int j=i+1;
		int z=i;
		map[i]=a[i];
		ans[i][j]=a[i];
		while(j!=n){
		  	if(map[i]==a[j]){
		    	z=j+1;
		    }
	    	j++;
	    }
		for(int l=z+1;l<n;l++){
			for(int u=l+1;u<n;u++){
				if(a[l]==a[u]){
					l=u;
				}
			}
		}   
		for(;z<n;z++){
			ans[i][z]=a[z]; 
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				if(ans[j][k]==i){
					sum[i]++;
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<' ';
	}
	return 0;
}
