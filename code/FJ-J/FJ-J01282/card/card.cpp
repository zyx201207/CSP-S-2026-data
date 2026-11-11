#include <bits/stdc++.h>
#define int long long
#define fs(i,x,y) for(int i=x;i<=y;i++)
#define fd(i,x,y) for(int i=x;i>=y;i--)
using namespace std;
const int N=5e5+7;
const int M=3e5+7;
signed a[N],b[N],c[M];
void Bol(){
	int n,m;
	scanf("%lld%lld",&n,&m);
	fs(i,1,n) scanf("%lld",&a[i]);
	fs(i,1,n){
		int k=1;
		memset(b,0,sizeof(b));
		fs(j,i,n){
			int z;
			bool flag=0;
			fs(v,1,k-1){
				if(flag){
					b[v]=0;
				}
				if(b[v]==a[j]){
					flag=1;
					z=v;
				}
			}
			if(flag){
				k=z-1;
			}
			b[k++]=a[j];
		}
		fs(v,0,k-1){
			c[b[v]]++;
		}
	}
	fs(i,1,m) printf("%d ",c[i]);
}
int T;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	T=1;
	while(T--){
		Bol();
	}
	return 0;
}
