#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll n,m,sum,l=1,ans;
ll a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int r=1;r<=n;r++){
		sum+=a[r];
		while(1ll*(r-l+1)*a[r]-sum>m){
			sum-=a[l];l++;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
} 
