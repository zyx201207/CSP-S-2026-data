//GZ-J00655 胡中睿
#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans2[300005];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int ans[300005]={0};
		for(int j=i;j<=n;j++){
			ans[a[i]]++;
		}
		for(int j=1;j<=m;j++){
			ans2[i]+=ans[i]%2;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans2[i]<<" ";
	}
	return 0;
}
