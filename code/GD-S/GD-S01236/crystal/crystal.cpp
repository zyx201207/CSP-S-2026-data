#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[500010],sum;
int main(){
	freopen("crystal.in" ,"r",stdin );
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	ll L=0,R=n;
	while(L<R){
		ll mid=(L+R+1)>>1;
		bool flag=false;
		sum=0;
		for(int i=1;i<mid;++i){
			sum+=a[i];
		}
		for(int i=mid;i<=n;++i){
			sum+=a[i]-a[i-mid];
			if(a[i]*mid-sum<=m){
				flag=true;
				break;
			}
//			cout<<i<<" "<<mid<<" "<<sum<<'\n';
		}
		if(flag)L=mid;
		else R=mid-1;
	}
	cout<<L;
	return 0;
} 
/*
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7
*/
