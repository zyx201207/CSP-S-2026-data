#include<bits/stdc++.h>
using namespace std;
int n,m,a[500500],tong[300300],sum[300300];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(tong[a[j]]==1){
				for(int x=1;x<=j;j++){
					if(a[x]==a[j]){
						for(int s=x;s<=j;s++){
							tong[a[s]]=0;
						}
					}
				}
				tong[a[j]]++;
			}
			else tong[a[j]]++;
		}
		for(int f=1;f<=m;f++){
			if(tong[f]==1) sum[f]++; 
		}
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<' ';
	}
	return 0;
}
