#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005]={ },c[300005]={ };
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			b[j]=a[j+i-1];
		}
		for(int j=1;j<=n-i+1;j++){
			for(int k=1;k<=j;k++){
				if(b[j]==b[k]){
					for(int l=j;l<k;l++){
						b[l]=0;
					}
				}
			}
		}
		for(int j=1;j<=n-i+1;j++){
			cout<<b[j]<<" ";
			c[b[j]]++;
		}
		cout<<endl;
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
