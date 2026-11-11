#include <bits/stdc++.h>
using namespace std;
long long a[200005],d,n,m,ans;
int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n>>m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	if(n==m){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout << ans;
	}
	if(m==1){
		ans=a[1];
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout << ans;
	}
	
	return 0;
}
