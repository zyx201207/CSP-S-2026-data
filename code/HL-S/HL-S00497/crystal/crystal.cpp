#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int i=1,j=1,tot=0;
	while(i<=n&&j<=n){
		j++;
		tot+=(j-i)*(a[j]-a[j-1]);
		if(tot>m){
			while(tot>m){
				tot-=a[j]-a[i];
				i++;
			}
		}
		ans=max(ans,j-i+1);
	}
	cout<<ans;
	return 0;
}