#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+7;
int a[N];
int n,m;
int s[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n<=5000){
		int ans=-1e9;
		for(int i=2;i<=n;i++){
			int sum=0;
			int j=i;
			while(1){
				sum+=a[i]-a[j];
				if(sum>m||j<1) break;
				j--;
			}
			ans=max(ans,i-j);
		}
		cout<<ans<<'\n';
		return 0;
	}
	else{
		int dc=a[2]-a[1];
//		for(int i=1;i<=n;i++){
//			xx[i]=i*dc;
//		}
//		for(int i=1;i<=n;i++){
//			s[]
//		}
		int i;
		for(i=n;i>=0;i--){
			int k=(dc+dc*i)*i/2;
			if(k<=m) break;
		}
		cout<<i<<'\n';
	}
	return 0;
}
/*
7
100
1 4 7 10 13 16 19


*/
