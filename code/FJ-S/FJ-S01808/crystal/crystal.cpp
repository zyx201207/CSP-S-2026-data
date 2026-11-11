//+100pts
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,a[N],ans,pre[N];
long long sum(long long j,long long i){
	return pre[i]-pre[j-1];
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
	for(int i=1;i<=n;i++){
		long long L=1,R=i,mid;bool f=false;
		while(L<=R){
			mid=(L+R)/2;
			long long x=(i-mid+1)*a[i]-sum(mid,i);
			if(x>m)L=mid+1;
			if(x<m)R=mid-1;
			if(x==m){
				f=true;
				ans=max(ans,i-mid+1);
				break;
			}
		}
		if(!f)ans=max(ans,i-R);
	}
	cout<<ans;
	return 0;
}