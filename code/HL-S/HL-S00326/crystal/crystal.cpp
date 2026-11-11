#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll  N=5e5+10;
ll f[N];
ll g[N],h[N];
bool k[N];
ll n,m,M;bool flag1=1,flag2=1;
void tf(bool flag1,bool flag2){
	ll ans=0;
	if(flag1==1){
		for(ll i = 1;i<=n;i++){
		
			ans+=i;if(ans>m){
			printf("%lld",i);return;}
		}printf("%lld",n);
		return ;
	}else if(flag2==1){
		for(ll i = 1;i<=n;i++){
			ans+=(f[3]-f[2])*i;
			if(ans>m){
			printf("%lld",i);return;}
		}printf("%lld",n);
		return ;
	}return ;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i = 1;i<=n;i++){	
	    scanf("%lld",&f[i]);
	    flag1=(f[i]==i);
		if(i>=3)flag2=(((f[i]-f[i-1])==(f[i-1]-f[i-2]))&flag2);
		g[i]=f[i]-f[i-1];
		k[i]=(f[i-1]>=f[i]?0:1);
		h[i]=(k[i]?h[i-1]+1:0);
	}
	if(flag1||flag2){
	tf(flag1,flag2);return 0;
	}
	ll maxx=0,cur=0,res;
	for(ll i = 1;i<=n;i++){
		cur=0,res=0;
		for(ll j = i+1;j<=n;j++){
		    cur+=(g[j]>0?(j-i)*g[j]:abs(g[j]));
		    if(g[j+1]<0&&g[j]<0)g[j+1]+=g[j];
			if(cur>m){maxx=max(maxx,j-i);break;
			}
		}
	}
	printf("%lld",(maxx==0?n:maxx));
	return 0;
}
