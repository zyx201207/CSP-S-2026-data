#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005],sum=-1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum=max(sum,(a[i-1]&a[i]));
	}cout<<sum;
	return 0;
}
