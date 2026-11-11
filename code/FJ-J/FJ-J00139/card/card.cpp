#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+1];
	int ans[m+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int i=1;i<=n;i++){
		int desk[n+1];
		int now=1;
		for(int j=1;j<=n;j++){
			//еп╤о 
			for(int k=1;k<now;k++){
			if(desk[k]==a[i]){
				for(int l=i-1;l>=1;l--){
					desk[l]=0;
				}
				desk[1]=a[i];
				now=1;
				continue;
				}
			}
			desk[now]=a[j];
			now+=1;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i];
	}
	return 0;
}
