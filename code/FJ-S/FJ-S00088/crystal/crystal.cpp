#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],sum,f,j,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	j=1;
	for(int i=2;i<=n;i++){
		sum+=(a[i]-a[i-1])*(i-1-f);
		while(j<i&&sum>m){
			sum-=a[i]-a[j];
			f++;
			j++;
		}
		ans=max(ans,i-j+1);
	}
	cout<<ans;
	return 0;
}
//I can solve T1,I am gui!/676767676767676767676767676767676767676767676767676767676767676767676767676767676767676767676767676767
//I love litelisi.
//lifes have end,arts do not have end.
