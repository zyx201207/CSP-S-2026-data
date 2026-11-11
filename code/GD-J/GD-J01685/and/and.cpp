#include <bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	cout<<a[m]<<endl;
	return 0;
}
