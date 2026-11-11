#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 5e5 + 5;
ll n,m,a[N],pre[N],ps[N],sum,idx;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++){
		pre[i]=a[i]-a[i-1];
		ps[i]=pre[i]+pre[i-1];
	}
	for(ll i=1;i<=n;i++){
		sum+=ps[i];
		if(sum>=m){
			idx=i-1;
			break;
		}
	}
	cout<<idx<<endl;
	return 0;
}
