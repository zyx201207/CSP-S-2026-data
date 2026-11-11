//GZ-J00179 遵义市红花岗区第十三小学 郭璟岩
#include <bits/stdc++.h>
using namespace std;
long long a[200005],mx=LONG_LONG_MIN;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			mx=max(mx,(a[i]&a[j]));
		}
	}
	cout<<mx;
	return 0;
}

