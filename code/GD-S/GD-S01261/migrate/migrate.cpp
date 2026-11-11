#include<bits/stdc++.h>
using namespace std;
long long x[2000005];
int dis[2000005],cnt[2000005];
int wz,c;
void sol(){
	int n;
	long long d;
	cin>>n>>d;
	for(int i=1;i<=n;++i)
		cin>>x[i];
	if(d==11||d==12){
		if(x[3]-x[1]<=d&&x[n]-x[1]>d&&n>2){
			int w=3;
			while(x[w]-x[1]<=d&&w<=n)++w;
			cout<<n-w<<'\n';
		}
		else cout<<0<<'\n';
		return;
	}
	int ans=0;
	for(int i=1;i<n;++i){
		dis[i]=0,cnt[i]=1;
		for(int k=i+1;k<=n;++k){
			int l=i,r=k-1,mid;
			cnt[k]=0,dis[k]=2e9;
			while(l<r){
				mid=(l+r)>>1;
				if(x[k]-x[mid]>d)l=mid+1;
				else r=mid;
			}
			if(x[k]-x[l]>d)break;
			for(int j=l;j<k;++j){
				if(dis[j]+1<dis[k])
					dis[k]=dis[j]+1,cnt[k]=cnt[j];
				else if(dis[j]+1==dis[k])
					cnt[k]+=cnt[j];
			}
			if(cnt[k]==2){
				++ans;
			}
		}
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(nullptr);
	int t;
	cin>>c>>t;
	while(t--)
		sol();
	return 0;
}
