#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int N=1e6+50;
ll n,m,a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	ll l=1,r=1,ans=1,cnt=m;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			ll need=a[j]-a[i];
			if(m>=need&&need>=0){
				m-=need;
				a[i]+=need;
			}else{
				break;
			}
		}
	}
	
	
	
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		if(a[i]==a[i+1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}

