
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5,M=1e6+5;
ll n,m,a[N],k,ans;
ll u=INT_MIN,lo=INT_MAX;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		u=max(u,a[i]);
		lo=min(lo,a[i]);
	}
	sort(a+1,a+n+1);
	ll cnt=0,t=m;
	for(int v=lo;v<=u;v++){
		for(int i=n;i>=1;i--){
			if(a[i]<=v){
				if(t>=v-a[i]){
					cnt++;
					t-=v-a[i];
				}
			}
		}
		ans=max(ans,cnt);
		cnt=0;
		t=m;
	}
	cout<<ans;
	return 0;
}

