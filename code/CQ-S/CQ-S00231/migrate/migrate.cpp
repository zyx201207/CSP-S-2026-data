#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5; 
int cc,t,n,cnt[N],l[N],sum[N];
long long a[N],d,s[N];
bool vis[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>cc>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		long long ans=0;
		if(cc<=10){
			for(int i=1;i<=n;i++){ 
			    for(int j=1;j<=n;j++) cnt[j]=0,sum[j]=-1;
			    cnt[i]=1,sum[i]=0,s[i]=1;
				for(int j=i-1;j>=1;j--){
					if(a[j]+d<a[j+1]) break;
					int p=upper_bound(a+1,a+n+1,d+a[j])-a-1;
					if(p>i) p=i;
					if(sum[p]==sum[j+1]) l[sum[p]]=j+1;
					if(p!=i) cnt[j]=s[l[sum[p]]]-s[min(p+1,l[sum[p]-1])];
					else cnt[j]=1;
					sum[j]=sum[p]+1;		
					s[j]=s[j+1]+cnt[j];
				} 
				for(int j=i+1;j<=n;j++){
					if(a[j]>a[j-1]+d) break;
					int p=lower_bound(a+1,a+n+1,a[j]-d)-a;
					if(p<i) p=i;
					if(sum[p]==sum[j-1]) l[sum[p]]=j-1;
					if(p!=i) cnt[j]=s[l[sum[p]]]-s[max(p-1,l[sum[p]-1])];
					else cnt[j]=1;
					sum[j]=sum[p]+1;
					s[j]=s[j-1]+cnt[j];
				} 
				for(int j=1;j<=n;j++) if(cnt[j]==2) ans++;
		    }
			cout<<ans/2<<"\n";
		}else if(cc<=12){
			cout<<n<<"\n";
		}else if(cc<=14){
			for(int i=1;i<=n;i++){
				if(a[i]-a[1]<=d && a[n]-a[i]<=d) vis[i]=1;
				else vis[i]=0;
			}
			int left;
			for(int i=n;i>=1;i--) if(vis[i]) left=i;
			int k1=0,k2=0; 
			if(left>1)  k1=upper_bound(a+1,a+n+1,a[left-1]+d)-a-1;
			if(left>2)  k2=upper_bound(a+1,a+n+1,a[left-2]+d)-a-1;
			for(int i=1;i<=n;i++){
				int p=upper_bound(a+1,a+n+1,a[i]+d)-a-1;
				if(p-left+1>2) break;
				if(p==left+1) ans+=n-max(p,k1);
				else ans+=n-max(p,k2);
			}
			cout<<ans<<"\n"; 
		}else if(cc<=16){
			cout<<n<<"\n";
		}
	}
	return 0;
}

