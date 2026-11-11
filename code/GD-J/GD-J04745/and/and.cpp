#include <bits/stdc++.h>
using namespace std;
int n,m,sum,a[10000005],b[10000005],maxn=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i]&a[i-1];
	}
	for(int i=2;i<=n;i++){
		if(b[i]|a[i-m]>maxn){
			maxn=b[i]|a[i-m];
		}
	}
	cout<<maxn;
	return 0;
} 
