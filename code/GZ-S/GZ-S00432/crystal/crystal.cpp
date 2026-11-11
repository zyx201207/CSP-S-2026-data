//贵阳市第三实验中学  刘家豪  GZ-S00432
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=501010;
int n,ans;
ll m;
ll a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(n>200000){
		ll sum=0;
		int d=a[2]-a[1];
		int o=1;
		while(o*(o+1)*d/2<=m)o++;
		cout<<o;
		return 0;
	}
	for(int i=1;i<=n;i++){
		ll cnt=0;
		for(int j=i;j>0;j--){
			if(a[j]<=a[i])cnt+=a[i]-a[j];
			if(cnt<=m)ans=max(ans,i-j+1);
			else {
				break; 
			}
		}
	}cout<<ans<<"\n";

	return 0;
}
