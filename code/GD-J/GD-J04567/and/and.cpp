#include<bits/stdc++.h>
using namespace std;
long long n,m,i,j,a[2000005],ans=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>a[i];
	sort(a,a+n+1);
	for(i=1;i<=m;i++)
	for(j=1;j<=n;j++){
		if(i!=j){
			ans=max(ans,(a[i]&a[j]));
		}
	}
	cout<<ans<<'\n';
	return 0;
}
