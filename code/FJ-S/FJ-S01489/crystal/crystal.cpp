#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
#define ll long long
const ll maxn=5e5+5;
const ll inf=1e18;
ll n,m;
ll a[maxn];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	ll l=1,r=1,ans=1,s=0;
	for(int i=2;i<=n;i++){
		s+=(r-l+1)*(a[i]-a[i-1]);
		r++;
		if(s>m){
			while(s>m){
				s-=a[i]-a[l];
				l++;
			}
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0; 
} 
