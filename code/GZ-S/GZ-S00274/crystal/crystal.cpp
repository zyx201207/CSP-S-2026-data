//GZ-S00274 贵阳市云岩区中天中学 张颜淏
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e6+10;

ll n,m,t1,t2;
ll a;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	cin>>n>>m;
	cin>>t1>>t2;
	ll temp=(t1-t2>t2-t1)?t1-t2:t2-t1;
	for(ll i=3;i<=n;i++){
		cin>>a;
	}
	
	ll i=0;
	ll tmp=1;
	while(i<=m){
		i+=tmp*temp;
		tmp++;
	}
	cout<<min(tmp-1,n)<<"\n";
	
    return 0;
}
