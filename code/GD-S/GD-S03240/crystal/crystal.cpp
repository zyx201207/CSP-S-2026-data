#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
ll n,m,a[N],b[N],pre[N],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){ cin>>a[i]; }
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++){ b[i]=a[i+1]-a[i]; }
	for(int i=1;i<n;i++){ pre[i]=pre[i-1]+b[i]; }
	ll l=1,r=1;
	ll sum=b[1];
	if(sum<=m) ans=1;
	for(int i=2;i<n;i++){  //n<=5e5;
		r=i;
		while(sum+(r-l+1)*b[i]>m&&l<r){
			sum-=(pre[r-1]-pre[l-1]);
			l++;
		}
		sum+=(r-l+1)*b[i];
		ans=max(ans,(r-l+1+1)); 
	}
	cout<<ans;
}
