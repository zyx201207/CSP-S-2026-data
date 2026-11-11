#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005],asu[500005],ans=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
            cin>>a[i];
	}sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
            asu[i]=asu[i-1]+a[i];
	}for(ll i=1;i<=n;i++){
        for(ll j=i-1;j>=0;j--){
            ll od=a[i]*(i-j)-asu[i]+asu[j];
            if(od<=m){
                ans=max(ans,i-j);
            }
        }
    }cout<<ans;
	return 0;
}
