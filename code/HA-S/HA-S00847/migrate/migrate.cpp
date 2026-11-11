#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d;
int a[2000001],b[2000001];
int check(int l,int r){
	int L=r-d,R=l+d;
	if(L>R)return 0;
	int ll=1,rr=n;
	int ans=n;
	while(ll<=rr){
		int mid=(ll+rr)>>1;
		if(a[mid]>=L){
			ans=min(ans,mid);
			rr=mid-1;
		}else{
			ll=mid+1;
		}
	}
	if(a[ans+2]>r)return 1;
	if(a[ans]>=L&&a[ans]<=R&&a[ans+1]>=L&&a[ans+1]<=R&&(a[ans+2]<L||a[ans+2]>R||a[ans+2]==r))return 2;
	if(a[ans]>=L&&a[ans]<=R&&(a[ans+1]<L||a[ans+1]>R))return 0;
	return 1;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			b[i]=b[i-1]+a[i];
		}int l=1,r=4,ans=0;
		while(r<=n){
			int fl=check(a[l],a[r]);
			if(fl){
				if(fl==2)ans++;
				r++;
			}else{
				l++;
			}
		}cout<<ans<<endl;
	}
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
