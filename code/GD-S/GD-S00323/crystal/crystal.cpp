#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500005;
int n,m,a[N],sum,ans,num,l;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	l=1;
	num=1;
	for(int i=2;i<=n;i++){
		sum+=(i-l)*(a[i]-a[i-1]);
		num+=1;
		while(sum>m){
			sum-=(a[i]-a[l]);
			l++;
			num--;
		}
		//cout<<i<<" "<<sum<<" "<<num<<" "<<ans<<endl;		
		ans=max(ans,num);
	}
	cout<<ans;
	return 0;
}
