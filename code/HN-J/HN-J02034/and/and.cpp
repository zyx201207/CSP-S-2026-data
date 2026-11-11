#include <bits/stdc++.h>
#define int long long
int n,m,a[200005],cnt,maxx=-1;
using namespace std;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=2;i--){
		for(int j=1;j<=m;j++){
			cnt=a[i]&a[i-1];
		}
		maxx=max(cnt,maxx);	
	}
	cout<<maxx;
	
	
	
	
	return 0; 
	
}
