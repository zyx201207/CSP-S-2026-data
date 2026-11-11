#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N=5e5+10;
ll n,m,a[N],st[N],ans[N];

int main(){
    freopen("card.in","r",stdin);
  	freopen("card.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(register int i=1; i<=n;i++){
        scanf("%lld",&a[i]);
    }
    for(register int i=1; i<=n;i++){
    	memset(st,0,sizeof st);
    	ll r=1;
    	st[r]=a[i];
    	for(register int j=i+1; j<=n;j++){
    		for(register int k=1; k<=r;k++){
    			if(st[k]==a[j]){
    				r=k-1;
    				break;
				}
			}
			r=r+1;
			st[r]=a[j];
		}
		for(register int j=1; j<=r;j++){
			ans[st[j]]=ans[st[j]]+1;
		}
	}
    for(register int i=1; i<=m;i++) printf("%lld ",ans[i]);
    return 0;
}
