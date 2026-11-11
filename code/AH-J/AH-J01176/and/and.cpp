#include<bits/stdc++.h>
using namespace std;
long long a[200000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long maxs=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			maxs=max(maxs,a[i]&a[j]);
		}
	}
	cout<<maxs;
    return 0;
}
