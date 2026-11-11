#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500010];
int nmax(int x,int y){
	if(x<y)return y;
	return x;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ans=1,s=0,t=1; 
	for(int i=2;i<=n;i++){
		s+=(a[i]-a[i-1])*(i-t);
		if(s>m){
			while(t<=i&&s>m){
				s-=(a[i]-a[t]);
				t++;
			} 
		}
		ans=nmax(ans,i-t+1);
	}
	cout<<ans;
	return 0;
}
