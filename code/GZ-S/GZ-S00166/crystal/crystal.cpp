//GZ-S00166 甘梓辰 贵阳市第一中学
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[500005],m;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=1,ans=1;
	for(int i=1;i<=n;i++){
		m-=(i-l)*(a[i]-a[i-1]);
		while(m<0){
			m+=a[i]-a[l];
			l++;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans<<endl;
	return 0;
}

