#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++) cin>>a[i];
	memset(ans,0,sizeof(ans));
	
	for(long long i=n;i>=1;i--){
		long long b[300005],tmp=0;
		for(long long j=i;j<=n;j++){
			bool is=0;
			for(long long k=tmp-1;k>=0;k--){
				if(b[k]==a[j]){
					is=1;
					break;
				}
			}
			if(is==1){
				for(;tmp>=0;tmp--){
					if(b[tmp]==a[j]) break;
					else b[tmp]=0;
				}
			}
			b[tmp++]=a[j];
		}
		for(long long i=0;i<tmp;i++) ans[b[i]]++;
	}
	for(long long i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
