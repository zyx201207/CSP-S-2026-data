#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N=2e5+888;
int n,m,a[N],s,d,len;
bool ch(int a,int b){
	 len=max(log2(a),log2(b));
	for(int i=len;i>=0;i--){
		 s=(a&(1<<i)),d=(b&(1<<i));
		if(s!=d){
			if(s>=d){
				return 1;
			}return 0;
		}
	}return 0;
}
bool cmp(int a,int b){
	return ch(a,b);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll t=1;
	//scanf("%lld",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		sort(a+1,a+1+n,cmp);
		int ans=0,j=1<<(int)(log2(a[1])),cntm=0,i,cnti;
		for(;j>=1;j=j>>1){
			cnti=0;
			for(i=1;i<=n&&cnti<m;i++){
				if((a[i]&ans)==ans){
					if((a[i]&j)==j){
						cnti++;
					}
				}
			}
			if(cnti>=m){
				ans+=j;
				//cntm++;
			}
		}
		printf("%d",ans);
	}
	return 0;
}
