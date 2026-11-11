#include<bits/stdc++.h>
using namespace std;
long long a[500053],s[500053];
int n,m,ans=1,rpl=0;
inline bool check(int k,int i){
	return -s[k]<=-s[i]+(a[n]-a[i])*(i-k)+rpl;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	rpl=m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+(a[n]-a[i]);
	for(int i=2;i<=n;i++){
		int l=0,r=i,fd=i;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(mid,i)){
				fd=mid;
				r=mid-1;//
			}else{
				l=mid+1;
			}
		}
		ans=max(ans,i-fd);
	}
	cout<<ans;
	return 0;
}
//14:53
