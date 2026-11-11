#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
typedef long long ll;
ll n,m,ans,as,x,tp,f;
ll a[N],cf[N],dis[N];
bool t=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
		dis[i]=dis[i-1]+a[i];
	}
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]>0 and tp==0){
			tp=a[i]-a[i-1];
			t=1;
		}
		if(a[i]-a[i-1]!=tp){
			t=0;
		}
		
	}
	if(t){
		x=m;
		for(int i=n-1;i>=1;i--){
			if(x-a[n]+a[i]>=0){
				ans++;
				x=x-a[n]+a[i];
			}
			else
			break;
		}
		cout<<ans+1<<'\n';
		return 0;
	}
	for(int i=n-1;i>=0;i--){
		for(int j=1;j+i<=n;j++){
			x=i*a[j+i]-dis[i+j-1]+dis[j-1];
			if(x<=m){
				f=1;
				ans=i+1;
			}
		}
		if(f){
			cout<<ans<<'\n';
			break;
		}
	}
    return 0;
}
