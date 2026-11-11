//crystal
#include<bits/stdc++.h>
#define p_b push_back
typedef long long ll;
using namespace std;
const int N=5e5+55;
int n,ans;
ll m,a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	ll sum=0;
	for(int l=1,r=2;r<=n;r++){
		sum+=(ll)(r-l)*(a[r]-a[r-1]);//将之前的全部补到a[r] 
		while(sum>m){
			sum-=a[r]-a[l];
			l++;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
/*
AC ver.
双指针

5 235234
4 4 4 3 3
*/
