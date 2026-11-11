#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+10;
ll c,t,n,d,i,x,y,l,r,le,ri,mid,cnt;
ll a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cnt=0;
		cin>>n>>d;
		for(i=1;i<=n;i++) cin>>a[i];
		for(i=n;i>=2;i--) a[i]-=a[i-1];
		a[1]=0;
		for(i=1;i<=n;i++) a[i]+=a[i-1];
		for(i=1;i<=n;i++){
			x=a[i]+d,y=a[i]+2*d;
			l=i+1,r=n;
			if(l==r) continue;
			while(l<r){
				mid=(l+r+1)/2;
				if(a[mid]-a[i]<=x) l=mid+1;
				else r=mid;
			}
			le=i+1,ri=n;
			if(le==ri) continue;
			while(le<ri){
				mid=(le+ri+1)/2;
				if(a[mid]-a[i]>=y) ri=mid-1;
				else le=mid;
			}
			if(l<=le&&l<=n&&le>=1) cnt+=le-l+1;
		}
		cout<<cnt<<endl;
	}
	return 0;
}
