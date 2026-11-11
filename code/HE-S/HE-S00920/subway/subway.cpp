#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005],b[500005];
ll ans = 0;//hello CCF kskbl
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		b[i] = abs(a[i]-a[i-1]);
	}
	sort(b+1,b+n+1);
	ll l = 1;
	while(m>0){
		if(b[l] == 0){
			l++;
			ans++;
		}	
		else{
			m-=b[l];
			if(m >=0){
				b[l] = 0;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
