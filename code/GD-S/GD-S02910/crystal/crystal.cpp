#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
const int N=5e5+5;
ll ans=0;
ll a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m;cin>>n>>m;
	bool flag=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i!=a[i])flag=false;
	}
	sort(a+1,a+n+1);
	if(flag){
		ll cnt=1;
		while(m>=0){
			m-=cnt;
			ans++;
			cnt++;
		}
	}else{
		for(int i=1;i<=n;i++){
			ll cnt=0,num=1;
			for(int j=i-1;j>0;j--){
				cnt+=a[i]-a[j];
				if(cnt>m){
					break;
				}
				num++;
			}
			ans=max(ans,num);
		}
	} 
	cout<<ans;
	
	return 0;
} 
