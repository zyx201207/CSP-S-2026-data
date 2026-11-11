#include<bits/stdc++.h>
using namespace std;
int a[10000],b[10000];
int s[10000][23];
int ans[10000][23];
int main(){
	int n,m;
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=1;j<=114514;j++){
			s[i][j]=a[i]%2;
			a[i]/=2;
			if(a[i]==0) break;
			b[i]=j;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			
			for(int z=1;z<=m;z++){
				
			}
		}
	}
	return 0;
}
