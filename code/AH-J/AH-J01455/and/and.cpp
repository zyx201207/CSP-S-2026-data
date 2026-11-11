#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,maxx,ans,a[200005];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=m;i<=n;i++){
		ans=0;
		for(int j=i-m+2;j<=i;j++){
			if(j==i-m+2)ans=a[j-1];
			ans=ans&a[j];
		}
		maxx=max(maxx,ans);
	}
	cout<<maxx;
	return 0;
}
