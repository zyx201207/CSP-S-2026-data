//GZ-J00476 遵义市播州区南白初级中学 卢语宸
#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[20000005];
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<a[n];
	return 0;
}

