#include<bits/stdc++.h>
#define pii pair<long long,char>
#define fi first
#define se second
#define ll long long
using namespace std;
const int N=2e5+5;
pii a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		ll cnt;char c;
		cin>>cnt>>c;
		a[i]={cnt,c};
	}
	int p1=1,p2=n;
	ll s1=a[1].fi,s2=a[n].fi;
	ll ans=0;
	while(1){
		if(p1==n+1||p2==0)break;
		ll ml=max(s1-a[p1].fi+1,s2-a[p2].fi+1),mr=min(s1,s2);
		ll cnt=mr-ml+1;
		if(a[p1].se!=a[p2].se){
			ans+=cnt;
		}
		if(s1<=s2){
			p1++;
			if(p1!=n+1)s1+=a[p1].fi;
		}else{
			p2--;
			if(p2!=0)s2+=a[p2].fi;
		}
	}
	cout<<ans/2;
	return 0;
}
