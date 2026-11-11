#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5;
ll n,m,a[N],mx;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
    	ll ans=0;
    	ll l=i,r=i,k=m;ans++;
    	while(l-1>=1&&r+1<=n){
    		ll s=a[i],x=s-a[l-1],y=a[r+1]-s;
    		if(k<min(x,y))break;
			if(x<y){
				k-=x;
    			l--;
    			ans++;
			}else{
				k-=y;
				r++;
				ans++;
			}
		}
		mx=max(mx,ans);
	}
	cout<<mx;
	return 0;
}
