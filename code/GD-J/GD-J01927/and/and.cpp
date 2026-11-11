#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int ans=0;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=n;i>=1;i--){
		for(int j=1;j<=m;j++){
			ans=max(ans,a[i]&a[j]);
		}
	} 
	cout<<ans;
	return 0;
}

