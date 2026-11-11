#include<bits/stdc++.h>
using namespace std;
long long a[200100];
bool b[200100];
long long f[200100];
long long n,m,maxh;
void ser(int t){
	for(int i=1;i<=n;i++){
		if(b[i]==0&&a[i]>=f[t-1]){
			f[t]=a[i];
			b[i]=1;
			if(t==m){
				long long ans=f[1];
				for(int j=2;j<=m;j++){
					ans=ans&f[j];
				}
				maxh=max(maxh,ans);
			}
			else ser(t+1);
			b[i]=0;
			f[t]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	ser(1);
	printf("%lld\n",maxh);
	return 0;
}


