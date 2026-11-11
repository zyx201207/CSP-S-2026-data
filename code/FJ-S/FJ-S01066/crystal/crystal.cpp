#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5;
int n,m,ans=0;
int a[N+5];
bool f=true;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<100) f=false;
	}
	sort(a+1,a+1+n);
	if(f&&n>N){
		int tmp=a[n]-a[n-1],num=0,cnt=0;
		while(num<=a[n]) num+=tmp*(++cnt);
		cout<<cnt;
		return 0;
	}
	for(int i=1;i<n;i++){
		int cnt=0,num=0;
		for(int j=i;j>=1;j--){
			if(num+a[i]-a[j]<=m){
				num+=a[i]-a[j];
				cnt++;
			}
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
