#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
typedef long long ll;
ll a[N],n,m,pr[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)pr[i]=pr[i-1]+a[i];
    int ans=0;
    for(int i=1;i<=n;i++){
    	int l=1,r=i+1,mid;
    	while(l<r){
    		mid=l+r>>1;
    		if(a[i]*(i-mid+1)-pr[i]+pr[mid-1]<=m)r=mid;
    		else l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
return 0;
}
