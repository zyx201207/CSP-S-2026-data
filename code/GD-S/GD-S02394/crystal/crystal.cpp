#include<iostream>
#include<algorithm> 
using namespace std;
#define int long long
const int MAXN=5e5+100;
int n,m,a[MAXN],ans;
int idx=1,cnt[MAXN],xa[MAXN],dif[MAXN],sum[MAXN];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	xa[idx]=a[1],cnt[idx]++;
	for(int i=2;i<=n;i++){
		if(xa[idx]==a[i]){
			cnt[idx]++;
			continue;
		}
		xa[++idx]=a[i];
		cnt[idx]++;
	}
	for(int i=1;i<=idx;i++){
		dif[i]=xa[idx]-xa[i];
		sum[i]=dif[i]*cnt[i];
	}
	for(int i=1;i<=idx;i++){
		cnt[i]+=cnt[i-1];
		sum[i]+=sum[i-1];
	}
	for(int i=1;i<=idx;i++){
//		for(int j=0;j<i;j++)
//			cout<<sum[i]-sum[j]-(cnt[i]-cnt[j])*dif[i]<<' ';
//		cout<<'\n';
		int l=0,r=i-1,res=0;
		while(l<=r){
			int mid=(l+r)/2;
			int cx=sum[i]-sum[mid]-(cnt[i]-cnt[mid])*dif[i];
			if(cx>=m){
				l=mid+1;
				res=mid;
			}else
				r=mid-1;
		}
		int cx=sum[i]-sum[res]-(cnt[i]-cnt[res])*dif[i];
		if(cx<=m){
			ans=max(ans,cnt[i]-cnt[res]);
		}else{
			int cy=sum[i]-sum[res+1]-(cnt[i]-cnt[res+1])*dif[i];
			int k=cnt[i]-cnt[res+1];
			//cerr<<k<<' '<<(m-cy)<<' '<<cnt[res+1]-cnt[res]<<' '<<xa[res+1]<<' '<<xa[i]<<'\n';
			k+=min(cnt[res+1]-cnt[res],(m-cy)/(xa[i]-xa[res+1]));
			ans=max(ans,k);
		}
	}
//	for(int i=1;i<=idx;i++)
//		cout<<cnt[i]<<' ';
	cout<<ans;
	return 0;
} 
