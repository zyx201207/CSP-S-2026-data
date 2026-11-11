#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	int a[n+1],b[n+1],c[m+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;i<=n;i++){
			b[i]=a[i];
		}
		for(int j=i;j<=n;j++){
			for(int k=i;k<j;k++){
				if(b[k]==b[j]){
					for(int l=k;l<=j;l++){
						if(b[l]>b[j]) b[l]=0;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			c[b[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
