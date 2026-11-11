#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n, m, i, j, ans=0;
	cin>>n>>m;
	for(i=0;i<n;i++){
		cin>>a[i];
		ans=max(ans,a[i]);
	}
	cout<<ans;
	return 0;
} 
