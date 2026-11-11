#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;
int c,T;
int n;
ll d;
ll a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(c==11||c==12||c==0){
			ll tmp=a[2]-a[1];
			if(d/tmp!=2)cout<<0<<'\n';
			else{
				cout<<max(0ll,n-d/tmp-1)<<'\n';
			}
		}else if(c==13||c==14){
			ll num=0;
			ll ans=0;
			int cnt=0;
			for(int i=1;i<=n;i++){
				if(a[i]-a[1]<=d&&a[n]-a[i]<=d){
					cnt++;
					num=i;
				}
			}
			if(cnt>=3){
				ans=0;
			}else if(cnt==1){
				ll x1=lower_bound(a+1,a+n+1,a[num+1]-d)-a;
				ll x2=lower_bound(a+1,a+n+1,a[num+2]-d)-a-1;
				ll x3=upper_bound(a+1,a+n+1,a[num-1]+d)-a;
				if(x1<num&&x2<num&&x3>num&&x3<=n)ans=ans+max(0ll,(x2-x1+1)*(n-x3+1));
				ll x4=x3-1,x5=upper_bound(a+1,a+n+1,a[num-2]+d)-a,x6=x1-1;
				if(x6>=1&&x6<num&&x4>num&&x5>num&&x4<=n&&x5<n)ans=ans+max(0ll,(x4-x5+1)*x6);
			}else{
				ll x1=lower_bound(a+1,a+n+1,a[num+1]-d)-a-1;
				ll x2=upper_bound(a+1,a+n+1,a[num-2]-d)-a;
				ans=max(0ll,x1*(n-x2+1));
			}
			cout<<ans<<'\n';
		}
	}
}
