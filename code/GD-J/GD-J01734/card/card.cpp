#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],b[200005],ans[200005];
map<long long,long long> p;
map<long long,long long> l;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]+a[i];
	}
	cout<<b[n/2]<<" "<<b[1]<<" "<<b[n]-b[n-m+1];
	return 0;
}
