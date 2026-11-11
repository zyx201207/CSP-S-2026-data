#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,ans,a[N],b[N];
char c1[N],c2[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld %c",&a[i],&c1[i]);
		b[n-i+1]=a[i],c2[n-i+1]=c1[i];
	} 
	int p=1,cura=0,curb=0;
	for(int i=1;i<=n;i++){
		int last=cura+1;
		cura+=a[i];
		while(p<=n){
			if(curb+b[p]>cura){
				if(c1[i]!=c2[p])ans+=cura-max(last,curb+1)+1;
				break;
			}else{
				if(c1[i]!=c2[p])ans+=min(cura,curb+b[p])-max(last,curb+1)+1;
				curb+=b[p];
				p++;
			}
		}
	}
	printf("%lld",ans/2);
	return 0;
}
