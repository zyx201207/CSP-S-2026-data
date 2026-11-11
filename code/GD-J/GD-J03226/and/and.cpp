#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
int a[N],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int j=1;j<=m;j++){
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]&a[i+j]);
		}	
	}
	cout<<ans;
	return 0;
}
