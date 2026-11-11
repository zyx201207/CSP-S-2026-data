#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,cnt=0;
	int a[200001],b[200001],c[200001];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<m;i++){
		for(int j=i;j<=m+i;j++){
			b[i]=a[j];
		}
	}
	for(int i=0;i<m;i++){
		c[i]=b[i]/b[i+1];
		cnt=max(c[i],c[i-1]);
	}
	cout<<cnt;
	return 0;
}
