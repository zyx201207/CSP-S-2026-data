#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct rr{
	ll a;
	char c;
}a[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n,nn=0;
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++){
		nn++;
		scanf("%lld %c",&a[nn].a,&a[nn].c);
		if(nn>1 && a[nn].c==a[nn-1].c){
			a[nn-1].a+=a[nn].a;
			nn--;
		} 
	}
	ll l=1,r=nn,cnt=0;
	while(l<r){
		if(a[l].c==a[r].c){
			if(a[l].a<a[r].a){
				a[r].a-=a[l].a;
				l++;
			}else if(a[l].a>a[r].a){
				a[l].a-=a[r].a;
				r--;
			}else l++,r--;
		}else{
			if(a[l].a<a[r].a){
				a[r].a-=a[l].a;
				cnt+=a[l].a;
				l++;
			}else if(a[l].a>a[r].a){
				a[l].a-=a[r].a;
				cnt+=a[r].a;
				r--;
			}else{
				cnt+=a[l].a;
				l++,r--;
			}
		}
	}
	printf("%lld",cnt);
	return 0;
}
