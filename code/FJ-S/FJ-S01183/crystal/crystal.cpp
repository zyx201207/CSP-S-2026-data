#include<bits/stdc++.h>
#define ll long long
#define FR(a,b,c) for(int a=b;a<=c;++a)
#define RF(a,b,c) for(int a=b;a>=c;--a)
using namespace std;
const int N=5e5+7;
ll n,m,l,r,a[N],ans,sum;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	FR(i,1,n)cin>>a[i];
	sort(a+1,a+1+n);
	while(1){
		if(sum+(r-l+1)*(a[r+1]-a[r])<=m){
			sum+=(r-l+1)*(a[r+1]-a[r]);
			r++;
		}else{
			sum-=(a[r]-a[l]);
			l++;
		}
		ans=max(ans,(r-l+1));
		if(r==n)break;
	}
	cout<<ans;
	return 0;
}
