#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll n,m,a[N];
int ans=-1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=n-1;i>=1;i--){
		ll k=a[i+1];
		ll s=m;
		int x=i;
		int ansn=1;
		while(s&&x>=1){
			if(k-a[x]>s) break;
			else{
				ansn++;
				s-=(k-a[x]);
				x--;
			}
		}
		ans=max(ans,ansn);
	}
	cout<<ans;
	return 0;
}
