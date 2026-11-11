#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const int N = 2e6+5;
ll t,c,n,d,a[N],st[N],ed[N],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans = 0;
		cin>>n>>d;
		for(int i = 1; i<=n; i++){
			cin>>a[i];
			st[i]=0,ed[i]=0;
		}
		sort(a+1,a+n+1);
		st[1]=1,ed[n]=n;
		for(int i = 2; i<=n; i++){
			int l=1,r=i;
			while(l<r){
				int mid = (l+r)>>1;
				if(a[mid]>=(a[i]-d)) r=mid;
				else l=mid+1;
			}
			st[i] = r;
		}
		for(int i = 1; i<n; i++){
			int l=i,r=n;
			while(l<r){
				int mid = (l+r+1)>>1;
				if(a[mid]<=(a[i]+d)) l=mid;
				else r=mid-1;
			}
			ed[i] = l;
		}
		for(int i = 2; i<=n; i++){
			for(int j = 1; j<i; j++){
				if(st[i]>=ed[j]) continue;
				if(ed[j]-st[i]+1>2) continue;
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
