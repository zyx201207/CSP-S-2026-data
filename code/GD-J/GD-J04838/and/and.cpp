#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	int maxn=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	cout<<maxn;
	return 0;
}
