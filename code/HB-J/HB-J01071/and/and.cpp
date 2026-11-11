#include<bits/stdc++.h>
using namespace std;
int a[200005],b[200005];
int n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int maxn=-9999;
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n;j++){
			int x=a[i]&a[j];
			maxn=max(maxn,x);
		}
	}
	cout<<maxn;
	return 0;
}
