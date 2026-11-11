#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=500010;
ll n,m;
ll a[N];
struct str{
	ll x,y;
};
str b[N];
ll cnt=0;
ll c[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	a[0]=-1e18;
	bool bol=0;
	ll lo=a[2]-a[1];
	for(int i=1;i<=n;i++){
		if(i!=1){
			if(a[i]-a[i-1]!=lo){
				bol=1;
			}
		}
		if(a[i]!=a[i-1]){
			++cnt;
			b[cnt]={a[i],1};
		}
		else{
			b[cnt].y++;
		}
    }
    if(bol==0){
    	ll ans=1;
    	for(int i=1;i<n;i++){
    		m=m-lo*i;
    		if(m>=0){
    			ans++;
			}
			else{
				break;
			}
		}
		printf("%lld\n",ans);
		return 0;
	}
    ll res=-1;
    bool bl=0;
    for(int i=cnt;i>=1;i--){
    	ll x=b[i].x,op=m,ans=b[i].y;
    	for(int j=i-1;j>=1;j--){
    		ll y=b[j].x;
    		ll ui=x-y;
    		if(ui>op){
    			break;
			}
    	    ll k=op/ui;
    	    if(k>=b[j].y){
    	    	k=b[j].y;
			}
			else{
				k=b[j].y-k;
			}
			ans+=k;
			op=op-k*ui;
			if(j==1&&op>=0){
				bl=1;
				break;
			}
		}
		if(ans>res){
			res=ans;
		}
		if(bl==1){
			break;
		}
	}
	printf("%lld\n",res);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
