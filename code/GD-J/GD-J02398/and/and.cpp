#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
bool bz[N];
int n,m;
ll a[N],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int s=32;s>=0;s--){//从最高位遍历位 
	    int cnt=0;
	    for(int i=1;i<=n;i++){
	    	if(bz[i]==1)continue;
	    	if((a[i]>>s)&1)cnt++;
		}
		if(cnt>=m){
			for(int i=1;i<=n;i++){
				if(!((a[i]>>s)&1))bz[i]=1;
			}
			ans+=(1<<s);
		}
	}
	printf("%lld",ans);
	return 0;
}
/*
4 2
3 15 12 12

5 3
31 3 1 15 7
*/
