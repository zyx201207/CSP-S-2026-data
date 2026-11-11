#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
int n,ans;ll m,a[N];
__int128 sum;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	  scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	int lx=1;
	ans=1,sum=0;
	for(int i=2;i<=n;i++){
		sum+=(__int128)(a[i]-a[i-1])*(i-lx);
		while(sum>m){
			sum-=(__int128)(a[i]-a[lx]);
			lx++; 
		}
		if(sum<=m) ans=max(ans,i-lx+1);
	}
	cout<<ans;
	return 0;
}
