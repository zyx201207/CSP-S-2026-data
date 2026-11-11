#include<bits/stdc++.h>
using namespace std;
const int N=2e6+33;
int c,t;
long long n,d,a[N];
int minn,cnt;
long long ans;
void dfs(int step,int x,int ot){
	if(x==ot){
		if(step==minn)cnt++;
		if(step<minn){
			minn=step;
			cnt=1;
		}
		return;
	}
	for(int i=x+1;i<=ot;i++){
		if(a[i]-a[x]<=d)dfs(step+1,i,ot);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				minn=INT_MAX;cnt=0;
				dfs(0,i,j);
				if(cnt==2)ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
