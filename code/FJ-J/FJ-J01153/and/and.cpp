#include<bits/stdc++.h>
using namespace std;
const int n_2=2*100000;
int a[n_2];
int x[n_2];
int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=INT_MIN;;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[j]<x[i]) x[i]=a[j]; 
		}
			if(x[i]>ans) ans=x[i];	
	}
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
