#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll a[500005];
int pre[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	scanf("%lld%lld",&n,&m);
	//ÌØÊâÐÔÖÊ 1-n
	if(m>100000){
		pre[0]=0;
		for(int i=1;i<=n;++i){
			scanf("%lld",&a[i]);
			pre[i]=pre[i-1]+a[i];
		}
		if(a[2]-a[1]==1){
			for(int i=1;i<=n;i++){
				if(m<pre[i]){
					printf("%d\n",i);
					return 0;
				}
				if(m==pre[i]){
					printf("%d\n",i+1);
					return 0;
				}
			}
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
