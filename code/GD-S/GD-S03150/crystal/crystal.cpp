#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
ll n,m,a[500005],b[500005],ans=1;
bool cmp(ll x,ll y){
	return x<y;
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
    	cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;++i){
    	b[i]=b[i-1]+a[i];
    	// ¢cout<<a[i]<<" ";
	}
	ll j=0;
    for(int i=1;i<=n;++i){
    	//for(int j=i;j>=1;--j){
    	do{
    		if(a[i]*(i-j)-b[i]+b[j]<=m){
    			ans=max(ans,(ll)i-j);
    			break;
			}
			//cout<<i<<" "<<j<<" "<<a[i]*(i-j)-b[i]+b[j]<<endl;
			j++;
		}while(a[i]*(i-j)-b[i]+b[j]>m);
	//	}
	}
	cout<<ans;
	return 0;
}
/*
5 8
-3 -1 2 2 7


4
crystal
subway
migrate
hub
y
*/
