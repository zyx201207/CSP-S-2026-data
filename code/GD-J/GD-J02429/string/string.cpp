#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using ll=long long;
pair<ll,char>a[200010];
ll n,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i].fi>>a[i].se;
	ll i=1,j=n;
	while(i<=j){
		if(a[i].se!=a[j].se){
			if(a[i].fi==a[j].fi){
				ans+=a[i].fi;
				i++;j--;
			}
			else if(a[i].fi>a[j].fi){
				ans+=a[j].fi;
				a[i].fi-=a[j].fi;j--;
			}
			else{
				ans+=a[i].fi;
				a[j].fi-=a[i].fi;i++;
			}
		}
		else{
			if(a[i].fi==a[j].fi)i++,j--;
			else if(a[i].fi>a[j].fi){
				a[i].fi-=a[j].fi;j--;
			}else{
				a[j].fi-=a[i].fi;i++;
			}
		}
	}
	cout<<ans;
	return 0;
}
