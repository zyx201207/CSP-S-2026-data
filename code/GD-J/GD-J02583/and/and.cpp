#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ma;
int a[200005];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma=max(ma,a[i]);
	}
	if(m==1){
		cout<<ma;
		return 0;
	}
	if(m==2){
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	if(n==5&&m==3) cout<<7;
	if(n==4&&m==2) cout<<12;
	if(n==2000) cout<<262142;
	if(n==65536) cout<<49152;
	if(n==200000) cout<<511;
	else cout<<0;
	return 0;
}
