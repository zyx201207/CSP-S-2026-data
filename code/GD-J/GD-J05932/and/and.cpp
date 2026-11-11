#include<bits/stdc++.h>
using namespace std;

int n,m;
long long maxn;
long long a[200005];

int main(){
	freopen("add.in","r",stdin);
	freopen("add.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long sum=a[n];
	for(int i=n-1;i>(n-m);i--){
		sum=(sum&a[i]);
	}cout<<sum;
	
	
}
