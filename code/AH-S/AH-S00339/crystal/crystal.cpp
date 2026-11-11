#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=5e5+101;
LL n,m;
LL a[N],di[N],ans=1,qzh[N];
bool isok(LL l,LL r){
	return (qzh[r-1]-qzh[l-1]-(r-l)*(a[n]-a[r]))<=m;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		qzh[i]=qzh[i-1]+a[n]-a[i];
		//cout<<a[n]-a[i]<<' '<<qzh[i]<<'\n';
	}//cout<<'\n';
	//for(int i=1;i<=n;i++)cout<<a[i];
	for(int i=1;i<=n;i++){
		di[i]=a[i]-a[i-1];
	}
	for(LL i=n;i>=1;i--){
		if(i<=ans)break;
		LL l=1,r=i,mid;
		while(l<r){
			mid=(l+r)/2;
			bool ok;
			ok=isok(mid,i);
			if(ok){
				ans=max(ans,i-mid+1);
				r=mid;
			}else l=mid+1;
		}
	}
	cout<<ans;
	return 0;
}




