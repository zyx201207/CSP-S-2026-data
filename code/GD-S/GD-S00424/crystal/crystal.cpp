#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n-1;i++){
		for(int j=1;j<=n-1;j++){
			if(a[j+1]>a[j]) swap(a[j+1],a[j]);
		}
	}
	for(int i=1;i<=n;i++){
		int tot;
		for(int j=i;j<=n;++j){
			tot+=(a[i]-a[j]);
		}
		if(tot==m){
			cout<<n-i+1;
			break;
		}
		else tot=0;
	}
	return 0;
 } 
