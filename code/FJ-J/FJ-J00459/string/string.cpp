#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;
typedef pair<ll,char> plc;

const int maxn=2e5+10;
ll n;
plc a[maxn];
ll ans=0;
void yes(){
	ll l=1,r=n;
	while(l<r&&l<=n&&r>=1){
		if(a[l].first<=a[r].first){
			if(a[l].second!=a[r].second){
				ans+=a[l].first;
			}
			a[r].first-=a[l].first;
			if(a[r].first==0)r--;
			l++;
		}
		else{
			if(a[l].second!=a[r].second){
				ans+=a[r].first;
			}
			a[l].first-=a[r].first; 
			r--;
		}
	}
	return;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].first>>a[i].second; 
	}
	yes();
	cout<<ans<<'\n';
	return 0;
}

