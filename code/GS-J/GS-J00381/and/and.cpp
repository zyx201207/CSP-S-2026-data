#include<bits/stdc++.h>
using namespace std;
int main(){
	int a[10010];
	freopen("and.in","r",stdin);
	freopen("and.out","r",stdin);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int b;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			b=a[i]&a[j];
		}
	}
	cout<<b;
	return 0;
}
