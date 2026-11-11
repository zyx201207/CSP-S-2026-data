#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
typedef long long ll;
ll m,a[N],c;
int n,ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	sort(a+1,a+1+n);
	a[0]=a[1];
	for(int i=1,j=1;i<=n&&j<=n;++j){
		int len=j-i+1;
		c+=(a[j]-a[j-1])*1ll*(len-1);
		while(c>m){
			c=c-(a[j]-a[i]);
			i++;
		}
		ans=max(ans,j-i+1);
//		if(ans==j-i+1)cout<<i<<" "<<c<<"\n";
	}
	cout<<ans;
	
	return 0;
}
