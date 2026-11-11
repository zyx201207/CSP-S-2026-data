#include <bits/stdc++.h>
using namespace std;
int a[500009],b[500009],c[500009];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)b[i]=a[i];
		for(int j=i;j<=n;j++){
			for(int k=1;k<j;k++){
				if(a[j]==a[k]){
					for(int p=k;p<j;p++)b[p]=0;
				}
			}
		}
		for(int j=1;j<=n;j++){
			c[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<c[i]<<" ";
	return 0;
}
