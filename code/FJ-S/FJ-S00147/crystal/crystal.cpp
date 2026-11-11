#include<bits/stdc++.h>
using namespace std;
#define int long long
int g[500001],g1[500001],m,n;
bool search(int k){
	int ans=9e18;
	for(int i=0;i<=n-k;i++){
		ans=min(g[k+i]*k-g1[k+i]+g1[i],ans);
		if(ans<=m)return 1;
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>g[i];
	sort(g+1,g+n+1);
	for(int i=1;i<=n;i++)g1[i]=g1[i-1]+g[i];
	int mi=1,ma=n;
	while(1){
		int mid=(ma+mi)/2;
		if(search(mid)){
			if(abs(ma-mi)<=1){
				cout<<mid;
				return 0;
			}mi=mid;
		}else ma=mid;
	}
}
