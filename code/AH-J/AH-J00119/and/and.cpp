#include<bits/stdc++.h>
using namespace std;
int a[2005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,maxn;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	maxn=a[1]&a[2];
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			maxn=max(maxn,a[i]&a[j]);
		}
	}
	cout<<maxn;
	return 0;
}
