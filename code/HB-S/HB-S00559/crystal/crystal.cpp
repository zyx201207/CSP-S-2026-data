#include <cstdio>
#include <algorithm>
#define N 500001
long long all[N];
long long pref[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;long long m;
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld",all+i);
    std::sort(all+1,all+n+1);
    for(int i=1;i<=n;i++) pref[i]=pref[i-1]+all[i];
    int mx=1;    
    for(int i=1;i<=n;i++){
	int L=1,R=i+1,ans=1;
	while(L<R){
	    int M=(L+R)>>1;
	    if(all[i]*M-(pref[i]-pref[i-M])<=m){
		L=M+1,ans=M;
	    }else{
		R=M;
	    }
	}
	if(mx<ans) mx=ans;
    }
    printf("%d\n",mx);
}
