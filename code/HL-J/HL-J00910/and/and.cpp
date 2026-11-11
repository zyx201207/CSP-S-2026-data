#include <bits/stdc++.h>
using namespace std;

long long n,m;
long long a[200005];
long long maxN=0;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=i;j<=m;j++){
			maxN=max((a[i]&a[i+1]),maxN);
		}
	}
	cout<<maxN;
	
	return 0;
}