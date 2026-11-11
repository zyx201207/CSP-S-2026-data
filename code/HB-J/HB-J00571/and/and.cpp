#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m;
int a[200001][32];
int f[101];
ll ans=0;
bool b[200001];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		ll x;
		scanf("%lld",&x);
		ll l=1<<30;
		for(int j=30;j>=0;j--){
			if(x>=l){
				x-=l;
				a[i][j]=1;
				f[j]++;
			}else
				a[i][j]=0;
			l/=2;
		}
	}
	for(int i=30;i>=0;i--){
		if(f[i]>=m){
			ans+=1<<i;
			for(int j=1;j<=n;j++){
				if(a[j][i]==0){
					for(int k=0;k<=i;k++){
						if(a[j][k]==1 && !b[j]){
							f[k]--;
						}
					}
					b[j]=1;
				}
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
