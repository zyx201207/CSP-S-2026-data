#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5;
ll n,m,a[N+5],ans=1;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(ll i=2;i<=n;i++){
		ll hf=0;
		bool ok=false;
		for(int j=i-1;j>=1;j--){
			hf+=(a[i]-a[j]);
			if(hf>m&&hf!=0){
				ans=max(ans,i-j);
				ok=true;
				break;
			}
			else if(hf==m&&hf!=0){
				ans=max(ans,i-j+1);
				ok=true;
				break;
			}
		}
		if(!ok){
			ans=max(ans,i);
		}
	}
	cout<<ans;
	return 0;
}
