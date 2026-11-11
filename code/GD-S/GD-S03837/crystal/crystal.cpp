#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e6+7;
int k[N]={},c[N]={};
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,b,ans=0;
	cin>>n>>b;
	for(int i=1;i<=n;i++)cin>>k[i];
	sort(k+1,k+n+1);
	for(int i=1;i<=n;i++)c[i]=abs(k[i]-k[i-1]);
	for(int i=1;i<=n;i++){
		int cnt=1,val=0,tot=0;
		for(int l=i-1;l>0;l--){
			val+=c[l+1];
			tot+=val;
			if(b>=tot)cnt++;
			else break;
		}ans=max(ans,cnt);
	}cout<<ans;
	return 0;
}
