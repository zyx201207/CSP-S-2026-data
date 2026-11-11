#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=2e6+5;
int c,t,n,d,ans,a[N],dis[N],sum[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>c>>t;
	if(c==11||c==12){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++)cin>>a[i];
			if(n==1)cout<<0<<endl;
			else{
				int k=d/(a[2]-a[1]);
				if(k<2||(k<<1)>n)cout<<0<<endl;
				else cout<<n-(k<<1)+1<<endl;
			}
		}
		return 0;
	}
	while(t--){
		cin>>n>>d;ans=0;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=n;i;i--){
			dis[i]=0;sum[i]=1;
			for(int j=i-1,k=i;j&&a[j+1]-a[j]<=d;j--){
				while(a[k]-a[j]>d)k--;
				dis[j]=dis[k]+1;sum[j]=sum[k];
				for(int l=k-1;l>j&&dis[l]==dis[k]&&sum[j]<3;l--)
					sum[j]+=sum[l];
				ans+=sum[j]==2;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
