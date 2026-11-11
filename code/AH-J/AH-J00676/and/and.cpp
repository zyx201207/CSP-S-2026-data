#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],c[35],maxn,sum,m;
bool b[200005][35],f[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		long long cnt=0;
		while(a[i]){
			b[i][++cnt]=a[i]%2;
			c[cnt]+=a[i]%2;
			a[i]/=2;
		}
		maxn=max(maxn,cnt);
	}
	for(int i=1;i<=n;i++){
		f[i]=1;
	}
	for(int i=maxn;i>=1;i--){
		if(c[i]>=m){
			long long cnt=0;
			for(int j=1;j<=n;j++){
				if(f[j]){
					if(b[j][i]){
						cnt++;
					}
				}
			}
			if(cnt>=m){
				for(int j=1;j<=n;j++){
					if(f[j]){
						if(!b[j][i]){
							f[j]=0;
						}
					}
				}
				sum+=1<<(i-1);
			}
		}
	}
	cout<<sum;
	return 0;
}
