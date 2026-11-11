#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+10;
ll n,m,a[N],p,ans;
ll f[31];
void pre(){
	f[0]=1;
	for(ll i=1;i<=30;i++) f[i]=f[i-1]*2;
}
bool cmp(const ll &x,const ll &y){
	return x>y;
}
int main(){
	pre();
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n,cmp);
	for(ll i=30;i>=0;i--)
		if(a[1]>=f[i]){
			p=i;
			break;
		}
	while(p>=0){
		if(a[m]>=f[p]){
			ans+=f[p];
			for(ll i=1;i<=n;i++){
				if(a[i]>=f[p]) a[i]-=f[p];
				else{
					n=i-1;
					break;
				}
			}
		}
		else{
			for(ll i=1;i<=n;i++){
				if(a[i]>=f[p]) a[i]-=f[p];
				else break;
			}
		}
		sort(a+1,a+1+n,cmp);
		p--;
	}
	cout<<ans;
	return 0;
}
