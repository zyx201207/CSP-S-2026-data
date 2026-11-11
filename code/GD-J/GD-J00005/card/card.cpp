#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[300005],c[300005];
long long q[500005],t;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int T=1;T<=n;T++){
		t=0;
		memset(b,0,sizeof(b));
		for(int i=T;i<=n;i++){
			if(b[a[i]]){
				for(int j=b[a[i]]+1;j<=t;j++) b[q[j]]=0;
				t=b[a[i]];
			}
			else{
				q[++t]=a[i];
				b[a[i]]=t;
			}
		}
		for(int i=1;i<=t;i++){
			if(q[i]) c[q[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		printf("%lld ",c[i]);
	}
}

