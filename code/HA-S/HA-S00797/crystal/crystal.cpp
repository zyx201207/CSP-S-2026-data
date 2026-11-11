#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500010];
ll cha,ans=-1,cnt,zan,q;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	q=m; 
	for(ll i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(ll j=1;j<=n;j++){
		for(ll i=j;i<=n;i++){
		    cha=a[i+1]-a[i];
		    m=m-cha*(i-j+1);
		    if(i==n)cnt=a[n];
		    if(m<0){cnt=a[i];break;}
		    else if(m==0){cnt=a[i+1];break;}
	    }
	    for(ll i=j;i<=n;i++){
		    if(cnt>=a[i])zan++;
	    }
	    ans=max(zan,ans);
	    zan=0;
	    m=q; 
	}
	cout<<ans<<endl;
	return 0;
}
