#include<bits/stdc++.h>
#define ll long long
#define N 200005

using namespace std;
ll n;ll ans=0;
struct s{
	ll ct;char t=' ';
}a[N];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i].ct>>a[i].t;
		if(a[i].t==a[i-1].t){
			a[i].t=' ';
			a[i-1].ct+=a[i].ct;
			a[i].ct=0;
			i--;n--;
		}
	}
	for(ll i=1,j=n;i<=j;i++,j--){
		if(a[i].t==a[j].t && a[i].ct==a[j].ct){
			continue;
		}
		if(a[i].ct==a[j].ct){
			ans+=a[i].ct;continue;
		}
		if(a[i].ct<a[j].ct){
			ll x=abs(a[j].ct-a[i].ct);ll len=a[i].ct+1;a[i].t=a[j].t;ans+=a[i].ct+x;
			while(x>0){
				if(a[len].ct>x){
					if(a[len].t==a[j].t){
						ans-=x;
					}
					a[len].ct-=x;a[len-1].ct+=x;x=0;break;
				}
				if(a[len].ct==x){
					if(a[len].t==a[j].t){
						ans-=x;
					}
					a[len].t=a[j].t;x=0;len++;break;
				}
				if(a[len].t==a[j].t){
					ans-=a[len].ct;
				}
				a[len].t=a[j].t;x-=a[len].ct;
				len++;
			}
			i=len-1;continue;
		}
	    else{
	    	ll x=abs(a[j].ct-a[i].ct);ll len=a[j].ct-1;a[j].t=a[i].t;ans+=a[j].ct+x;
	    	while(x>0){
				if(a[len].ct>x){
					if(a[len].t==a[i].t){
						ans-=x;
					}
					a[len].ct-=x;a[len+1].ct+=x;x=0;break;
				}
				if(a[len].ct==x){
					if(a[len].t==a[i].t){
						ans-=x;
					}
					a[len].t=a[i].t;x=0;len--;break;
				}
				if(a[len].t==a[i].t){
					ans-=a[len].ct;
				}
				a[len].t=a[i].t;x-=a[len].ct;
				len--;
			}
			j=len+1;continue;
		}
	}
	cout<<ans;
	return 0;
}
