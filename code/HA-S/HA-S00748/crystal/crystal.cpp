#include<bits/stdc++.h>
using namespace std;
#define N 500010
#define ll long long
#define ull unsigned long long
ll n,m,a[N],l=1,r=1,ans,sum;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	while(r<=n){
		sum+=a[r];
		while(a[r]*(r-l+1)-sum>m){
			sum-=a[l];
			++l;
		}
		ans=max(ans,r-l+1);
		++r;
	}
	cout<<ans;
	return 0;
}
