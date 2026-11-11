#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],b[300010],c[500010];
int main(){
	freopen("card","r",stdin);
	freopen("card","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			c[j]=a[j];
			for(int k=i;k<=j;k++){
				if(c[k]==c[j]){
					for(int l=k;l<j;l++){
						c[l]=0;
					}
				}
			}
		}
		for(int j=i;j<=n;j++){
			b[c[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
