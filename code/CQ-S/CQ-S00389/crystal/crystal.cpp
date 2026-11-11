#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+7;
int a[N],n,m;
int sum[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int ans=1;
	for(int l=1;l<=n;l++){
		for(int length=ans;length+l-1<=n;length++){
			int r=length+l-1;
			if(length*a[r]-(sum[r]-sum[l-1])<=m){
				ans=r-l+1;
			}
			else{
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}

