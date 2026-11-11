#include<bits/stdc++.h>
using namespace std;
const int maxn=2000005,maxt=100005;
long long a[maxn],d[maxn],ans[maxt];
int main(){
	memset(d,0,sizeof(d));
	memset(ans,0,sizeof(ans));
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n;
	long long x,mn=2*1e18,mx=0;
	cin>>c>>t;
	for(int i=0;i<t;i++){
		cin>>n>>x;
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
		sort(a+1,a+n+1);
		for(int j=2;j<=n;j++){
			d[j]=a[j]-a[j-1];
			mx=max(mx,d[j]);
			mn=min(mn,d[j]);
		}
		if(x<mn){
			ans[i]=0;
			continue;
		}
		if(mx==mn){
			long long num=x/mx;
			ans[i]=n-num*2+1;
			if(ans[i]<0){
				ans[i]=0;
			}
		}
	}
	for(int i=0;i<t;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}
