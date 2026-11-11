#include<bits/stdc++.h>
using namespace std;
struct A{
	char c;
	long long a;
}v[220000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%lld",&v[i].a);
		cin>>v[i].c;
	}
	long long lx=0,rx=n-1,ln=v[0].a,rn=v[n-1].a,ans=0;
	char lc,rc;
	while(lx<=rx){
		lc=v[lx].c,rc=v[rx].c;
		if(ln>rn){
			if(lc!=rc){
				ans+=rn;
			}
			ln-=rn;
			rn=0;
			rx--;
			rn+=v[rx].a;
		}else if(ln<rn){
			if(lc!=rc){
				ans+=ln;
			}
			rn-=ln;
			ln=0;
			lx++;
			ln+=v[lx].a;
		}else{
			if(lc!=rc){
				ans+=ln;
			}
			rn-=ln;
			ln=0;
			lx++;
			rx--;
			rn+=v[rx].a;
			ln+=v[lx].a;
		}
	}
	cout<<ans;
	return 0;
}
