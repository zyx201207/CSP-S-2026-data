#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=5e5+10;
typedef long long ll;
ll n,a[maxn],m;
int main(){
	//freopen("/home/csps/Downloads/crystal/crystal2.in","r",stdin);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	ll j=1,sum=0,ans=0;
	for(int i=1;i<=n;i++){
		sum+=(i-j)*(a[i]-a[i-1]);
		while(sum>m){
			sum-=(a[i]-a[j]);
			j++;
		}
		ans=max(ans,i-j+1);
	}
	cout<<ans<<'\n';
	return 0;
}
