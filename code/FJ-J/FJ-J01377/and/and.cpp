#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+10;
ll n,m,a[N];
ll b[38]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824};
ll f,ans=0;
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;++i){
		f=1;
		for(int j=0;j<=30;++j){
			if(a[i]==b[j]){
				f=0;
				break;
			}
		}
		if(f){
			if(ans==0)
				ans=a[i];
			else ans&=a[i];
			m--;
		}
		if(m<=0)break;
	}
	cout<<ans;
	return 0;
}
