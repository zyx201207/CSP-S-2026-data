#include<bits/stdc++.h>
using namespace std;
long long n,m,q[100000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >>n>>m;
	for(int i=1;i<=n;i++){
		cin>>q[i];
	}
	sort(q+1,q+n+1);
	int ans=q[m];
	cout << ans;
	return 0;
}
