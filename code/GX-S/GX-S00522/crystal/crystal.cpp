#include<bits/stdc++.h>
using namespace std;
#define int long long

int n,m,a[500005];
int pre[500005];
const int oft=0ll;

int erfen(int ll,int rr){
	//cout<<"erfen "<<ll<<" to "<<rr<<endl;
	int l=ll,r=rr,mid;
	int res=rr+1;
	int hi=a[rr+1];
	while(l<=r){
		mid=(l+r)>>1;
		int c=hi*(rr-mid+1)-(pre[rr]-pre[mid-1]);
		//cout<<"--mid="<<mid<<" c="<<hi*(rr-mid+1)<<endl;
		if(c<=m){
			res=mid;
			r=mid-1;
		}
		else{
			l=mid+1;
		}
	}
	//cout<<"--res="<<res<<endl;
	return res;
}

int ans=0;

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);

	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]+=oft;
	}
	sort(a+1,a+1+n);
	pre[0]=0;
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}

	for(int i=2;i<=n;i++){
		//choose i;
		int kkk=erfen(1,i-1);
		ans=max(ans,i-kkk+1);
	}

	cout<<ans<<endl;

	return 0;
}