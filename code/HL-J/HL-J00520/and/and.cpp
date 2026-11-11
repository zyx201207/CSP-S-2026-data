#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N],b[N],sum;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int o=0;
	for(int i=n-1;i>=n-m-1;i--){
		b[o++]=a[i];
	}
	int k=b[0];
	for(int i=1;i<m;i++){
		k=k&b[i];
		sum=k;
	}
	cout<<sum;
	return 0;
}

