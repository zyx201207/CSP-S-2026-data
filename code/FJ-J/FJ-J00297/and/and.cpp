#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int ans=0,sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum=max(sum,a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			ans=max(ans,(a[i]&a[j]));
		}
	}
	if(m==1) cout<<sum;
	else cout<<ans;
	return 0;
}
