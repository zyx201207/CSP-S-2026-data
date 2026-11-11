#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
int n,qz[N];
ll a[N],lsh[N],qzh[N],k,id[N];
bool check(int x,int now){
	if((qz[now]-qz[x-1])*id[now]-(qzh[now]-qzh[x-1])<=k) return true;
	return false; 
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0); 
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i],lsh[i]=a[i];
	sort(lsh+1,lsh+n+1);
	int len=unique(lsh+1,lsh+n+1)-lsh-1;
	for(int i=1;i<=n;i++){
		int l=lower_bound(lsh+1,lsh+len+1,a[i])-lsh;
		qz[l]++,qzh[l]+=a[i],id[l]=a[i];
	}
	for(int i=1;i<=len;i++) qz[i]+=qz[i-1],qzh[i]+=qzh[i-1];
//	for(int i=1;i<=len;i++) cout<<qz[i]<<" "<<qzh[i]<<"\n";
	int ans=0;
	for(int i=1;i<=len;i++){
		int l=1,r=i;
		while(l<r){
			int mid=(l+r)>>1;
			if(check(mid,i)) r=mid;
			else l=mid+1;
		}
//		cout<<l<<"\n";
		int cnt=(qz[i]-qz[l-1])*id[i]-(qzh[i]-qzh[l-1]),w=qz[i]-qz[l-1];
		if(l!=1) w+=(k-cnt)/(id[i]-id[l-1]);
		ans=max(ans,w);
	}
	cout<<ans<<"\n"; 
	return 0;
}
