#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[200008];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int o;
	for(int i=1;i<=n;i++){
		for(int j=1;j<n;j++){
			if(a[j]<a[j+1]){
				int u=a[j];
				a[j]=a[j+1];
				a[j+1]=u;
			}
		}
	}
	o=a[1];
	for(int i=2;i<=m;i++){
		o=o&a[i];
	}
	cout<<o;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
