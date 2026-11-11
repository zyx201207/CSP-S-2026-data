#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+5;
long long c,t,n,d,x[maxn],jian,ans,a[maxn],cnt[maxn];
void dfs(long long X,long long sum){
	if(sum<a[X]){
		a[X]=sum;
		cnt[X]=1;
	}else if(sum==a[X])cnt[X]++;
	for(int i=X+1;i<=n;i++){
		if(x[i]-x[X]>d)return;
		dfs(i,sum+1);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		if(c==11||c==12){
			jian=d/(x[2]-x[1]);
			if(jian==0||jian==1)cout<<"0"<<'\n';
			else cout<<max((long long)0,n-2*jian+1)<<'\n';
			continue;
		}
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				a[j]=INT_MAX;
				cnt[j]=0;
			}
			a[i]=0;
			dfs(i,0);
			for(int j=i+1;j<=n;j++)
				if(cnt[j]==2)ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
