#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
const int N=5e5+5;
int n;
ll m,a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	int r=1,ans=0;
	ll res=0;
	for(int l=1;l<=n;l++){
		res-=a[r]-a[l];
		while(r<n){
			ll x=(a[r+1]-a[r])*(long long)(r-l+1);
			if(m-x>=res){
				r++;
				res+=x;
			}
			else break;
		}
		ans=max(r-l+1,ans);
	}
	cout << ans;
	return 0;
} 
