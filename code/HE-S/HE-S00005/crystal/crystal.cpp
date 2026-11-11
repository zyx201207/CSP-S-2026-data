//14:45 cai ji ba xie wan wo yao wan dan le
//guan zhu dreambiggod xie xie miao 
//100pts?
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=6e5;
int n,m,a[N],s[N],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)s[i]=s[i-1]+a[i];
	for(int i=n;i>=1;--i){
		int l=1,r=i,p=0;
		while(l<=r){
			int mid=(l+r)/2;
			if(a[i]*(i-mid+1)-s[i]+s[mid-1]<=m)p=mid,r=mid-1;
			else l=mid+1;
		}
		ans=max(ans,i-p+1);
	}
	cout<<ans<<'\n';
	return 0;
}
