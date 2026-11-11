# include<bits/stdc++.h>
# define int long long
using namespace std;
int nxt[1000001],a[1000001],n,d,c,t;
int DP1[5001],sum1[5001],ans;
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)nxt[i]=0;
	
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<=2)return cout<<"0\n",void();
	for(int i=1;i<=n;i++){
		if(i<n){
			int l=i,r=n;while(l<r){int mid=(l+r+1)>>1;if(a[mid]-a[i]<=d)l=mid;else r=mid-1;}nxt[i]=l;
		}
	}
	if(n<=5000){//基本分 
		
		ans=0;
		for(int i=n;i;i--){
			for(int j=1;j<=i;j++)DP1[j]=n+1,sum1[j]=0;
			DP1[i]=0,sum1[i]=1;
			for(int j=i-1;j;j--){
				if(nxt[j]==j)break;
				for(int k=min(i,nxt[j]);k>j&&sum1[j]<3&&DP1[k]==DP1[nxt[j]]&&sum1[k];k--)sum1[j]+=sum1[k];//最多3次 
				DP1[j]=DP1[nxt[j]]+1,sum1[j]=min(3ll,sum1[j]);
				if(sum1[j]==2)ans++;
			}
		}
		cout<<ans<<"\n";
		return;
	}
	if(c==11||c==12){
		if(nxt[1]<=2)return cout<<"0\n",void();
		int v=nxt[1]-1,ans=0;
//		cerr<<v<<"\n";
		for(int i=1;i<=n;i++){
			if(i+2*v-1<=n)ans++;
		}
		cout<<ans<<"\n";
		return;
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--)solve();
}
