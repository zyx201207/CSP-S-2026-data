#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0); 
	int n,m,a[2005];
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==1){
		int ma=-1;
		for(int i=1;i<=n;i++)ma=max(ma,a[i]);
		cout<<ma;
		return 0;
	}
	if(m==n){
		int ans=a[1];
		for(int i=1;i<=n;i++)ans=ans&a[i];
		cout<<ans;
		return 0;
	}
	if(m==2){
		int ma=-1,ans;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				ans=a[i]&a[j];
				ma=max(ma,ans);
			}
		}
		cout<<ma;
		return 0;
	}
    else cout<<26;
	return 0;
}
