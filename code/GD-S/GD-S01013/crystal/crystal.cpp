#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define f(i,a,b) for(int i=a;i<=b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
const int N=1e6+10;
ll n,m,ar[N],pre[N],ans;
bool check(ll x,ll y){
	if(ar[y]*(y-x+1)-(pre[y]-pre[x-1])<=m)return true;
	else return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	f(i,1,n){
		cin>>ar[i];
	}
	sort(ar+1,ar+1+n);
	f(i,1,n)pre[i]=pre[i-1]+ar[i];
	f(i,1,n){
		ll r=i,l=1,mid;
		while(r>=l){
			mid=(r+l)/2;
			if(check(mid,i)){
				r=mid-1;
			}else l=mid+1;
//			cout<<ar[i]*(i-mid+1)-pre[i]
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
