#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	int n,m,ans,maxx=-1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-m+1;j++){
			ans=a[j];
			for(int k=j+1;k<=m-1;k++){
				ans&&=a[k];
			}
			maxx=max(maxx,ans);
		} 
	}
	printf("%d",maxx);
	return 0;
}

