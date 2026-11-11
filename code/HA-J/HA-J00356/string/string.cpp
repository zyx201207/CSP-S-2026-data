#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct num{
	char c;
	ll sum;
};
ll n;
num a[200005];
num b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i].sum>>a[i].c;
		if(a[i-1].c==a[i].c){
			a[i-1].sum+=a[i].sum;
			i--;
			n--;
		}
	}
	ll p=1;
	for(ll i=n;i>=1;i--){
		b[p].c=a[i].c;
		b[p].sum=a[i].sum;
		p++;
	}
	ll ans=0;
	p=1;
	for(ll i=1;i<=n&&p<=n;){
		if(b[p].sum>a[i].sum){
			if(b[p].c!=a[i].c){
				ans+=b[p].sum-a[i].sum;
			}
			b[p].sum-=a[i].sum;
			i++;
		}
		else if(b[p].sum==a[i].sum){
			if(b[p].c!=a[i].c){
				ans+=b[p].sum;
			}
			i++;
			p++;
		}
		else if(b[p].sum<a[i].sum){
			if(b[p].c!=a[i].c){
				ans+=a[i].sum-b[p].sum;
			}
			a[i].sum-=b[p].sum;
			p++;
		}
		
	}
	cout<<ans/2;
	return 0;
}

