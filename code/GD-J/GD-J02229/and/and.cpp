#include<bits/stdc++.h>
using namespace std;
long long a[200001],maxn=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		long long b=a[i]&a[i+1];
		maxn=max(maxn,b);
	}
	cout<<maxn;
	return 0;
}
