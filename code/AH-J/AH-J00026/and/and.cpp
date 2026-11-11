#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll a[200010],b[200010];
bool cmp(const ll &x,const ll &y){
	return x>y;
}	
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}	
	ll t=1,s=0;
	bool ok=0;
	ll sum=0;
	sort(a+1,a+n+1,cmp);
	for(ll i=30;i>=1&&m!=0&&t<=n;i--){
		ll d=(1ll<<i);
		if(a[t]>=d){
			if(a[t+1]>=d&&m-2>=0){
				if(ok==0){
					ok=1;
					sum=a[t];
				}
				sum&=a[t];
				sum&=a[++t];
				m-=2;
			}else{
				b[++s]=a[t];
				a[t]=0;
				t++;
			}	
		}	
	}	
	sort(b+1,b+s+1,cmp);
	for(ll i=1;m!=0&&i<=s;i++){
		if(sum==0) sum=b[i];	
		sum&=b[i];
		m--;
	}	
	while(m--){
		if(sum==0) sum=a[t+1];
	    sum&=a[++t];
	}
	cout<<sum;
	return 0;
} 
