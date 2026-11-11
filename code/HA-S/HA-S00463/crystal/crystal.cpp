#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m;
int a[N],dp[N];
int ans=1;
int cha,f=1;
void sol(){
	int sum=0;
	for(int i=2;i<=n;i++){
		sum=sum+(i-1)*(a[i]-a[i-1]);
		if(sum>m){
			break;
		}
		ans++;
	}
	cout<<ans;
	return;
}
signed main(){
	freopen("crystal","r",stdin);
	freopen("crystal","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>1&&i==2){
			cha=a[i]-a[i-1];
		}else if(i>1){
			if(a[i]-a[i-1]!=cha){
				f=0;
			}
		}
	}
	if(f==1){
		sol();
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		int maxx=1,sum=0;
		for(int j=i;j<=n;j++){
			sum=sum+(j-i+1)*(a[j]-a[j-1]);
			if(sum>m){
				break;
			}
			maxx++;
		}
		ans=max(ans,maxx);
	}
	cout<<ans;
	return 0;
}
//70tps
