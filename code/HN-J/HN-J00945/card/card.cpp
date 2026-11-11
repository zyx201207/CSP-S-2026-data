#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
long long d[300005];
bool c[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(long long i=1;i<=n;i++){
		vector<long long>b;
		for(long long i=1;i<=m;i++){
			c[i]=false;
		}
		for(long long j=i;j<=n;j++){
			if(c[a[j]]){
				while(b.back()!=a[j]){
					c[b.back()]=false;
					b.pop_back();
				}
			}else{
				b.push_back(a[j]);
				c[a[j]]=true;
			}
		}
		for(long long j=1;j<=m;j++){
			d[j]+=c[j];
			c[j]=false;
		}
	}
	for(long long i=1;i<=m;i++){
		printf("%lld ",d[i]);
	}
	return 0;
}
