#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=5e5+10;

int n,m,a[N],sum[N],ans=0,now=0;

bool cmp(int a,int b){return a<b;}

signed main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false); cin.tie(0);
	
	cin>>n>>m;
	
	for(int i=1;i<=n;i++) cin>>a[i];
	
	sort(a+1,a+1+n,cmp);
	
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	
	ans=1; now=1;
	
	for(int i=1;i<=n;i++){
		
		while(now<i&&a[i]*(i-now+1)-sum[i]+sum[now-1]>m) now++;
		
		ans=max(ans,i-now+1); 
		
	}
	
	cout<<ans;
	 
	
}
