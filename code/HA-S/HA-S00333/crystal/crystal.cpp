#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll N=5e5+7;
ll n,m,a[N],b[N],ans;
bool f=0;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==0){
		cout<<0<<'\n';
		return 0;
	}
	sort(a+1,a+n+1);
	for(i=1;i<n;i++){
		b[i]=a[i+1]-a[i];
	}
	ll l=1,r=n,mid=(l+r)/2;
	while(l<=r){
		mid=(l+r)/2;
		ll cnt=0,sum=0;
		bool f1=0;
		for(j=1;j<=n;j++){
			if(j<mid){
				sum+=b[j];
				cnt+=(b[j]*j);
			}else{
				if(cnt<=m){
					ans=max(ans,mid);
					f=1;
					f1=1;
					break;
				}
				cnt-=sum;
				cnt+=(b[j]*(mid-1));
				sum=sum+b[j]-b[j-mid+1];
			}
		}
		if(f1==0){
			r=mid-1;
		}else{
			l=mid+1;
		}
	}
	if(f==0){
		cout<<n<<'\n';
	}else{
		cout<<ans<<'\n';
	}
	return 0;
}
