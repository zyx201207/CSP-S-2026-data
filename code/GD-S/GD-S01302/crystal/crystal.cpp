#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll n,m,a[N],p,i,t,cnt,ans=LLONG_MIN,c,k;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	bool f=true;
	if(n>=2){
		k=a[2]-a[1];
		for(i=2;i<n;i++)
			if(k!=(a[n+1]-a[n])){
				f=false;break;
			}
	}
	
	if(f==true){
		cnt=0;
		for(i=1;i<n;i++){
			if(a[i]==a[i+1]) continue;
			c=(a[i+1]-a[i]);
			if(cnt+c*(i-t+1)<=m) cnt+=c*i;
			else break;
		}
	}else{
		for(t=1;t<=n;++t){
			cnt=0;
			for(i=t;i<n;i++){
				if(a[i]==a[i+1]) continue;
				c=(a[i+1]-a[i]);
				if(cnt+c*(i-t+1)<=m) cnt+=c*i;
				else break;
			}
			ans=max(ans,i-t+1);
		}
	}
	cout<<ans<<"\n";
	return 0;
}
