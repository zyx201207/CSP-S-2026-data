#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[300001];
bool b[300001];
long long c[300001];
long long d[300001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
	for(int i=1;i<=n;++i){
		int j=i,r=0;
		for(;j<=n;++j){
			if(b[a[j]]==0){
				++r;
				b[a[j]]=r;
				c[r]=a[j];
			}else{
				for(;c[r]!=a[j];--r){
					b[c[r]]=0;
				}
			}
		}
		for(int e=1;e<=r;++e){
			b[c[e]]=0;
			d[c[e]]++;
		}
	}
	for(int i=1;i<=m;++i)printf("%lld ",d[i]);
}
