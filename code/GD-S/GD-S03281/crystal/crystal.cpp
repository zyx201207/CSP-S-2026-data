#include<bits/stdc++.h>
#define ll long long
#define fo(i,x,y) for(int i=(x);i<=(y);i++)
#define fr(i,x,y) for(int i=(x);i>=(y);i--)
using namespace std;
const int N=5e5+5;
ll a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	ll m,s=0;
	int n,p=1,ans=1;
	cin>>n>>m;
	fo(i,1,n)
		cin>>a[i];
	sort(a+1,a+1+n);
	fo(i,1,n){
		s+=(a[i]-a[i-1])*(i-p);
		while(p<i&&s>m)
			s-=a[i]-a[p++];
		ans=max(ans,i-p+1);
	}
	cout<<ans;
	return 0;
}
