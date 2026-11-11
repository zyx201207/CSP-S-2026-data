#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n,maxn=-1;
	cin>>n>>m;
	int a[n+2];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n-1;i++){
		for(int j=i+1;j<=n;j++){
			maxn=max(maxn,(a[i]&a[j]));
		}
	}
	cout<<maxn;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
