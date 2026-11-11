//GZ-S00054 张世铠 贵阳市白云区华师一学校 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ll maxx=-1;
	for(int i=1;i<=n;i++){
		if(a[i]==a[i+1]){
			continue;
		}
		ll cost=0,most=0;
		for(int j=i-1;j>=0;j--){
			cost+=a[i]-a[j];
			if(cost>m){
				break;
			}
			most++;
		}
		maxx=max(maxx,most+1);
	}
	cout<<maxx;
	return 0;
}
