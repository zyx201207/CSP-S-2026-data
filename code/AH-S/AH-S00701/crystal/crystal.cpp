#include<bits/stdc++.h>
using namespace std;
long long n,m,m1,a[123456789],i,ans=-1;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
    freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	m1=m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(i=2;i<=n;i++){
		m1=m;
		for(int j=i-1;j>=1;j--){
			m1=m1-(a[i]-a[j]);
			if(m1<0){
				if(i-j+1>ans) ans=i-j+1;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
