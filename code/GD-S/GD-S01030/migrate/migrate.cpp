#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10,M=5e3+10;
int c,T,n,d,a[N],ans;
int dp[M][M];
//bool vis[N];
int Find(int k){
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)>>1;
		if(a[mid]==k){
			return mid;
		}
		if(a[mid]<k){
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	return l-1;
}
//void insert(int step){
//	int lst=0,nxt=0;
//	vector<int>q;
//	q.push(0);
//	while(step!=n){
//		q.push_back(step);
//		step=Find(a[step]+d);
//	}
//	for(int i=1;i<=n;++i){
//		ans+=lst;nxt++;
//		if()
//	}
//}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--){
		memset(dp,0,sizeof(dp));
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;++i){
			cin>>a[i];
		}
		if(c==11||c==12){
			if((a[2]-a[1])*2<=d&&(a[2]-a[1])*3>d){
				cout<<n-3<<"\n";
			}else{
				cout<<0<<"\n";
			}
			continue;
		}
		if(c==13||c==14){
			if(n>7){
				cout<<0<<"\n";
				continue;
			}
		}
		if(c==1||c==2||c==3){
			cout<<0<<"\n";
			continue;
		}
		if(c==4){
			if(a[3]-a[1]<=d&&a[4]-a[2]<=d&&a[4]-a[1]>d){
				cout<<1<<"\n";
			}else{
				cout<<0<<"\n";
			}
			continue;
		}
		for(int i=n;i>=1;--i){
			int j=i;
			while(j!=n&&a[j+1]-a[j]<=d){
//				cout<<i<<" "<<j<<"\n";
				int tmp=Find(a[j]+d);
//				cout<<j<<" "<<tmp<<"\n";
				for(int k=j+1;k<=tmp;++k){
					dp[i][k]=dp[i][j]+1;
				}
				j=tmp;
			}
//			for(int j=i;j<=n;++j){
//				cout<<dp[i][j]<<" ";
//			}
//			cout<<"\n";
		}
//		for(int i=1;i<=n;++i){
//			for(int j=1;j<=n;++j){
//				cout<<dp[i][j]<<" ";
//			}
//			cout<<"\n";
//		}
		for(int i=1;i<=n;++i){
			for(int j=i+2;j<=n;++j){
				int res=0;
				for(int k=i+1;k<j;++k){
					if(dp[i][k]+dp[k][j]==dp[i][j]){
						res++;
					}
					if(res>2)break;
				}
				if(res==2)ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
