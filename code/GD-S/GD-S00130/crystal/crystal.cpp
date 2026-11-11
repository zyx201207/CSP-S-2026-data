#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=1e6+10;
#define lid(id) (id<<1)
#define rid(id) (id<<1|1)

ll n,m,a[maxn],s[maxn],ans;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	double st=clock();
//	freopen("")
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	stable_sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	
	for(int i=1;i<=n;i++){
		ll l=1,r=i,mid;
		while(l<=r){
			ll mid=l+r>>1;
			if((i-mid+1)*a[i]-(s[i]-s[mid-1])<=m)ans=max(ans,i-mid+1),r=mid-1;
			else l=mid+1;
		}
	}cout<<ans;
//	double ed=clock();
//	cout<<ed-st;
	return 0;
} 
