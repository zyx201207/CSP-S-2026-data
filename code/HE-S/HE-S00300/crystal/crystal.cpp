#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
ll n,m,a[N],ans;
int main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+1+n);
	ll w=0;
	for(int i=1,j=1;i<=n;i++){
		ll len=i-j+1;
		w+=(a[i]-a[i-1])*(len-1);
		while(w>m){
			w-=a[i]-a[j];
			j++,len--;
		}
		ans=max(ans,len);
	}
	cout << ans;
	return 0;
}/*
5 5
1 2 4 8 9
*/
