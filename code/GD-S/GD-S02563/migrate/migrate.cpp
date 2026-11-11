#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll c,t,n,d,a[2000010],dp[2000010],cnt[2000010],pre[2000010],lst[2000010],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	cin>>c>>t;while(t--){
		cin>>n>>d,ans=0;for(int i=1;i<=n;i++)cin>>a[i];
		if(c>=11&&c<=12){
			d=d/(a[2]-a[1]);
			if(d<=1)cout<<"0\n";
			else cout<<max(0ll,n-(d*2-1))<<'\n';
			continue;
		}
		for(int i=1;i<=n;i++){
			for(int j=0;j<=n;j++)lst[j]=pre[j]=0;
			dp[i]=0,cnt[i]=1,pre[i]=1,lst[0]=i;
			for(int j=i+1,k=i;j<=n;j++){
				while(a[j]-a[k]>d)k++;
				dp[j]=dp[k]+1,cnt[j]=pre[lst[dp[k]]]-pre[k-1],pre[j]=pre[j-1]+cnt[j],lst[dp[j]]=j;
				if(cnt[j]==2)ans++;
			}
		}
		cout<<ans<<'\n';
	}
}
