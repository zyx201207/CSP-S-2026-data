#include <bits/stdc++.h>
using namespace std;

const int maxn=2e5+5;
int a[maxn];

int main(){
	freopen("and.in","w",stdin);
	freopen("and.out","r",stdout);
	
	int n,m;
	cin>>n>>m;
	
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int ans=1;
	for(int i=n; i>=n-m+1; i--){
		ans=max(ans&a[i],1);
	}
	cout<<ans<<endl;
	return 0;
}
