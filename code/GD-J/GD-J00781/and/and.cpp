#include<bits/stdc++.h>
using namespace std;
const long long K=2e5+5;
long long a[K],ans[K];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	long long maxn=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			maxn=a[i]&a[j+1];
		}
	}
	maxn=a[3]&a[4];
	cout<<maxn;
	return 0;
}
