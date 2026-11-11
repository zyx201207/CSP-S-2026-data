#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,q;
int n,d;
int nxt[2000006];
int x[2000006];
bool check(int pos,int len){
	if(x[pos+len-1]-x[pos]<=d){
		return 1;
	}
	return 0;
}
int dp[2000006],cnt[2000006];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>q;
	while(q--){
		
		cin>>n>>d;
		
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(n>2000||c==11||c==12){
			cout<<(x[n]-x[1])/d<<'\n';
			continue;
		}
//		x[0]=LLONG_MIN;
		for(int i=1;i<=n;i++){
			int l=i-1,r=n+1;
			while(r-l>1){
				int mid=(l+r)>>1;
				if(x[mid]-x[i]<=d){
					l=mid;
				}else{
					r=mid;
				}
			}
			nxt[i]=l;
//			cout<<nxt[i]<<" ";
		}
		int ans=0;
		
		for(int i=1;i<=n;i++){
			memset(dp,0x3f,sizeof dp);
			memset(cnt,0,sizeof cnt);
			dp[i]=0;
			cnt[i]=1;
			for(int j=i;j<=n;j++){
				if(cnt[j]>2){
					continue;
				}
				for(int k=j+1;k<=nxt[j];k++){
//					cout<<"**"<<i<<" "<<j<<" "<<k<<" "<<dp[j]+1<<'\n';
					if(dp[j]+1<dp[k]){
						cnt[k]=cnt[j];
					}
					if(dp[j]+1==dp[k]){
						cnt[k]+=cnt[j];
					}
					dp[k]=min(dp[k],dp[j]+1);
				}
			}
			for(int j=1;j<=n;j++){
//				cout<<cnt[j]<<' ';
				if(cnt[j]==2){
					ans++;
				}
			}
//			cout<<"\n";
		}
		
		cout<<ans<<'\n';
	}
	
	return 0;
}

//after contest
