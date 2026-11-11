#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 5e5;
ll n,m;
ll a[N];
ll d[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	freopen("D:\\csps-new\\down\\crystal\\crystal3.in","r",stdin);
//	freopen("D:\\csps-new\\down\\crystal\\out.txt","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans = -1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[j]>a[i]){
				d[j] = (1ll<<60);
			}else{
				d[j] = a[i]-a[j];
			}
		}
		sort(d+1,d+1+n);
		ll sum=0;
		int cnt=0;
		for(int j=1;j<=n;j++){
			sum+=d[j];
			if(sum>m){
				break;
			}
			cnt++;
		}
		ans = max(ans,cnt);
	}
	cout<<ans<<endl;
	return 0;
}
