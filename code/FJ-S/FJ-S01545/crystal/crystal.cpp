#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500001],ans=0,c,b;
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m>1e9){
		ans=n;
	}
	else{
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			c=b=0;
			for(int j=1;j<i;j++){
				c+=a[i]-a[j];
				if(c>m){
					b=1;
					ans=max(ans,j);
					break;
				}
			}
			if(!b) ans=max(ans,i);
		}
	}
	cout<<ans;
	return 0;
}
