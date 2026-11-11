#include<bits/stdc++.h>
#define int long long
using namespace std;
int x[2000009],dp[2000009],dp2[2000009],q[2000009],f=1,h=1;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,t,n,d,ans;
	cin>>c>>t;
	if(c<=10){
		while(t--){
			ans=0;
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>x[i];
			}
			for(int r=1;r<=n;r++){
				dp[r]=0;
				dp2[r]=1;
				f=1,h=1;
				for(int i=r+1;i<=n;i++){
					dp[i]=0;
					dp2[i]=0;
				}
				q[h]=r;
				h++;
				for(int i=r+1;i<=n;i++){
					if(x[i]-x[i-1]>d)break;
					while(f!=h){
						if(x[i]-x[q[f]]>d)f++;
						else break;
					}
					dp[i]=dp[q[f]]+1;
					dp2[i]=dp2[q[f]];
					if(f+1<h){
						if(dp[q[f+1]]==dp[q[f]]){
							dp2[i]+=dp2[q[f+1]];
						}
					}
					if(f+2<h){
						if(dp[q[f+2]]==dp[q[f]]){
							dp2[i]+=dp2[q[f+2]];
						}
					}
					while(f!=h){
						if(dp[q[h-1]]>dp[i]){
							h--;
						}else break;
					}
					q[h]=i;
					h++;
				}
				for(int i=r+1;i<=n;i++){
					if(dp2[i]==2){
						ans++;
					}
				}
			}
			cout<<ans<<"\n";
		}
	}else if(c<=12){
		while(t--){
			ans=0;
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>x[i];
			}
			int r=1;
			dp[r]=0;
			dp2[r]=1;
			f=1,h=1;
			for(int i=r+1;i<=n;i++){
				dp[i]=0;
				dp2[i]=0;
			}
			q[h]=r;
			h++;
			for(int i=r+1;i<=n;i++){
				if(x[i]-x[i-1]>d)break;
				while(f!=h){
					if(x[i]-x[q[f]]>d)f++;
					else break;
				}
				dp[i]=dp[q[f]]+1;
				dp2[i]=dp2[q[f]];
				if(f+1<h){
					if(dp[q[f+1]]==dp[q[f]]){
						dp2[i]+=dp2[q[f+1]];
					}
				}
				if(f+2<h){
					if(dp[q[f+2]]==dp[q[f]]){
						dp2[i]+=dp2[q[f+2]];
					}
				}
				while(f!=h){
					if(dp[q[h-1]]>dp[i]){
						h--;
					}else break;
				}
				q[h]=i;
				h++;
			}
			for(int i=r+1;i<=n;i++){
				if(dp2[i]==2){
					ans+=n-i+1;
				}
			}
			cout<<ans<<"\n";
		}
	}else{
		while(t--){
			ans=0;
			cin>>n>>d;
			int u=0;
			for(int i=1;i<=n;i++){
				cin>>x[i];
			}
			for(int i=1;i<=n;i++){
				if(x[i]-x[1]<=d&&x[n]-x[i]<=d)u=i;
			}
			if(n<=3){
				cout<<"0\n";
				continue;
			}
			if(u!=1){
				for(int i=1;i<=n;i++){
					if(u+1<=n&&x[u+1]-x[i]<=d)break;
					int k=upper_bound(x+1,x+1+n,x[i]+d)-x,l=upper_bound(x+1,x+1+n,x[u-1]+d)-x;
					if(u>2)k=max(k,upper_bound(x+1,x+1+n,x[u-2]+d)-x);
					ans+=l-k;
				}
			}
			for(int i=1;i<=n-i+1;i++){
				swap(x[i],x[n-i+1]);
			}
			for(int i=1;i<=n;i++){
				x[i]=-x[i];
			}
			u=n+1-u;
			if(u!=1){
				for(int i=1;i<=n;i++){
					if(u+1<=n&&x[u+1]-x[i]<=d)break;
					int k=upper_bound(x+1,x+1+n,x[i]+d)-x,l=upper_bound(x+1,x+1+n,x[u-1]+d)-x;
					if(u>2)k=max(k,upper_bound(x+1,x+1+n,x[u-2]+d)-x);
					ans+=l-k;
				}
			}
			cout<<ans<<"\n";
		}
		
	}
	return 0;
}
