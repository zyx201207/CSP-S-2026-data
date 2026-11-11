//GZ-J00028 贵阳市白云区华师一学校 白杨梦雪 
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=200005;
ll a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	ll ans=0;
	if(n==m){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	else if(m==2){
		ans=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	else if(m==1){
		m=0;
		for(int i=1;i<=n;i++){
			if(a[i]&a[i]>ans) ans=a[i]&a[i];
		}
		cout<<ans;
	}
	return 0;
}
