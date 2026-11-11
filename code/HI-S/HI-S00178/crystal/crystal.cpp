#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int N=5e5+10;
ll n,m,l,r,ans=0;
ll a[N],b[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i = 1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	for(int k = 1;k<=n;k++){
		l=1;
		r=k;
		while(l<r){
			ll mid=(l+r)/2;
			ll len=k-mid;
			if(len*a[k]-(b[k-1]-b[mid-1])<=m){
				r=mid;
			}
			else{
				l=mid+1;
			}
		}
		ans=max(ans,k-l+1);
	}
	cout << ans << endl; 
	return 0;
}

