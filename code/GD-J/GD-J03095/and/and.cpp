#include <bits/stdc++.h>
using namespace std;
long long n,m,maxn,a[200005],sum;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}if(m==n){
		maxn=a[1];
		for(int i=2;i<=n;i++){
			maxn=(maxn&a[i]);
		}cout<<maxn;
		return 0;
	}sort(a+1,a+n+1);
	for(int j=1;j<=n-m+1;j++){
		sum=a[j];
		for(int i=2;i<=m;i++){
			sum=(sum&a[i+j-1]);
		}maxn=max(maxn,sum);
	}cout<<maxn;
	return 0;
} 
