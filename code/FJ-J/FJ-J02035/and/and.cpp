#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e5+5;
ll n,m,a[N],ans,f[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(ll i=1;i<=n;i++){ 
		f[0]=a[i];
		for(int j=min(i,m);j>=1;j--){
			f[j]=max(f[j],(f[j-1]&a[i]));
			//printf("%lld %lld %lld\n",i,j,f[j]);
		}
	}
	cout<<f[m]<<endl;
	return 0;
}
