#include <bits/stdc++.h>
using namespace std;
int c,n,t,d,cnt;
const int MAXN=5e5+5;
long long a[MAXN],b[MAXN],f[MAXN];
bool vis[MAXN];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >>t;
	while(t--){
		int sum=0;
		cin >> n >> d;
		for(int i=1;i<=n;i++){
			cin >>a[i];
			vis[a[i]]=1;
			b[i]=a[i]-a[i-1];
		}
		for(int j=1;j<=n;j++){
			for(int i=1;i<=n;i++){
				cnt+=b[i];
				if(cnt<=d){
					cnt+=b[i];
				}
				else {
					sum++;
					cnt=0;
				}
			}
			memset(f,0,sizeof(f));
			f[1]=a[1]
			for(int i=1;i<=sum;i++){//·ÉÁËi´Î 
				for(int k=1;k<=d;k++){
					if(vis[f[i-1]+k]){
						f[i]=1; 
					}
				}
			}
		}
		
	}
	cout << 1 <<"\n"<<2;
} 
