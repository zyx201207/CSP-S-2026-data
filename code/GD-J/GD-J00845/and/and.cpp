#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5+5;
long long a[maxn],mx,ans;
bitset<maxn> f[35];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	if(n>2000){
		for(int i = 1;i<=n;i++){
			for(int j = 0;(1<<j)<=a[i];j++){
				mx = max(mx,j+0ll);
				if((a[i]>>j)&1){
					f[j][i] = 1;
				}
			}
		}
		for(int i = 1;i<=n;i++){
			f[mx+1][i] = 1;
		}
		bitset<maxn> e = f[mx+1];
		for(int j = mx;j>=0;j--){
//			cout<<j<<" "<<(e&f[j]).count()<<"\n";
			if((int)(e&f[j]).count()>=m){
				ans+=(1ll<<j);
				e&=f[j];
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==1){
		for(int i = 1;i<=n;i++){
			mx = max(mx,a[i]);
		}
		cout<<mx;
	}
	else if(m==2){
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=n;j++){
				if(j!=i){
					mx = max(mx,a[i]&a[j]);
				}
			} 
		}
		cout<<mx;
	}
	else if(m==n-1){
		long long h = a[1];
		for(int i = 2;i<=n;i++){
			h&=a[i];
		}
		for(int i = 1;i<=n;i++){
			long long k = 0;
			for(long long j = 1;(1ll<<(j-1))<=a[i];j++){
				if(!(a[i]>>(j-1))&1 and !(h>>(j-1))&1){
					k+=(1ll<<(j-1));
				}
			}
			mx = max(mx,k);
		}
		cout<<h+mx;
	}
	else if(*max_element(a+1,a+1+n)<=4){
		int u[5] = {0,0,0,0,0};
		for(int i = 1;i<=n;i++){
			u[a[i]] = 1;
		}
		for(int i = 0;i<5;i++){
			for(int j = 0;j<5;j++){
				mx = max(mx,(i&j)*u[i]*u[j]*1ll);
			}
		}
		cout<<mx;
	}
	else{
		for(int i = 1;i<=n;i++){
			for(int j = 0;(1<<j)<=a[i];j++){
				mx = max(mx,j+0ll);
				if((a[i]>>j)&1){
					f[j][i] = 1;
				}
			}
		}
		for(int i = 1;i<=n;i++){
			f[mx+1][i] = 1;
		}
		bitset<maxn> e = f[mx+1];
		for(int j = mx;j>=0;j--){
//			cout<<j<<" "<<(e&f[j]).count()<<"\n";
			if((int)(e&f[j]).count()>=m){
				ans+=(1ll<<j);
				e&=f[j];
			}
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
