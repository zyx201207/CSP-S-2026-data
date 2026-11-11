#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=5e5+5;
int n,m,a[N],f[N],ans=1;
__int128 w[N];

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	
	sort(a+1,a+1+n);
	
	int L=1;
	w[1]=0;
	f[1]=1;
	for(int i=2;i<=n;i++){
		if(a[i]==a[i-1]){
			f[i]=f[i-1]+1;
			w[i]=w[i-1];
			ans=max(ans,f[i]);
			continue;
		}
		
		__int128 len=i-L;
		w[i]=w[i-1]+len*(a[i]-a[i-1]);
		
		while(w[i]>m){
			w[i]-=(__int128)(a[i]-a[L]);
			L++;
		}
		
		f[i]=i-L+1;
		ans=max(ans,f[i]);
	}
	
	cout<<ans<<'\n';
	return 0;
}
