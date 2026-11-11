#include<iostream>
#include<cstdio>
#include<algorithm>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],b[N],cnt[N],len,ans;
inline int getid(int x){
	return lower_bound(b+1,b+len+1,x)-b;
}
inline bool check(int x,int id,int tot){
	int num=cnt[id-1];
	int sum=a[num]-a[num-tot+x];
	int cost=b[id]*(tot-x)-sum;
	return cost<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	len=unique(b+1,b+n+1)-b-1;
	for(int i=1;i<=n;++i)++cnt[getid(a[i])];
	for(int i=1;i<=n;++i)a[i]+=a[i-1],cnt[i]+=cnt[i-1];
	int tot=cnt[1];
	ans=cnt[1];
	for(int i=2;i<=len;++i){
		int l=0,r=tot;
		int num=0;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(mid,i,tot))r=mid-1,num=mid;
			else l=mid+1;
		}
		tot=tot-num+cnt[i]-cnt[i-1];
		ans=max(ans,tot);
	}
	cout<<ans<<'\n';
	return 0; 
}

//100pts
