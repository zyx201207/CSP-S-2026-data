#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int cnt=a[i];
		for(int j=i+1;j<i+m;j++){
			cnt=cnt&a[j];
			ans=max(ans,cnt);
		}
	} 
	cout<<ans;
	return 0;
} 
