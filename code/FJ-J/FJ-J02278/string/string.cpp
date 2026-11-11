#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+3;
int a[N],q[N],cnt[N],ccnt[27][N];
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		q[i]=q[i-1]+a[i];
	}
	int ans=0;
	if(q[n]&1){
		int o=(q[n]+1)/2;
		int l=1,r=n;
		while(l<=r){
			int mid=l+r>>1;
			if(q[mid]<=o)l=mid+1;
			else r=mid-1;
		}
		int mi=o-q[l-1];
		ans+=abs(a[l]-mi*2-1);
		for(int i=1;i<l;i++){
			cnt[c[i]-'a'+1]+=a[i];
		}
		for(int i=l+1;i<=n;i++){
			ans+=abs(cnt[c[i]-'a'+1]-a[i]);
			cnt[c[i]-'a'+1]-=a[i];
		}
	}else{
		int o=q[n]/2;
		int l=1,r=n;
		while(l<=r){
			int mid=l+r>>1;
			if(q[mid]<=o)l=mid+1;
			else r=mid-1;
		}
		int mi=o-q[l-1];
		ans+=abs(a[l]-mi*2);
		for(int i=1;i<l;i++){
			cnt[c[i]-'a'+1]+=a[i];
		}
		for(int i=l+1;i<=n;i++){
			ans+=abs(cnt[c[i]-'a'+1]-a[i]);
			cnt[c[i]-'a'+1]-=a[i];
		}
	}
	cout<<ans;
	return 0;
}
