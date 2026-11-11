#include<bits/stdc++.h>
#define ll long long
#define inc(i,l,r) for(int i=l;i<=r;i++)
#define dec(i,r,l) for(int i=r;i>=l;i--)
using namespace std;
const int N=5e5+10;
ll a[N],s[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n,m;
	cin>>n>>m;
	inc(i,1,n){
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	sort(a+1,a+n+1);
	ll l=1,r=n;
	ll maxn=0;
	while(l<r){
		ll mid=(l+r)>>1;
		if(a[mid]*(mid-1)-s[mid-1]<=m){
			l=mid+1;
			maxn=mid;
		}
		else{
			r=mid;
		}
	}
	inc(i,l+1,n){
		ll j=i-1;
		ll tot=a[i]-a[j];
		while(j>0&&tot<=m){
			maxn=max(maxn,i-j+1);
			j--;
			tot+=a[i]-a[j];
		}
	}
	cout<<maxn;
}
